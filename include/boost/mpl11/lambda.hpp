/*!
 * @file
 * This file defines `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_LAMBDA_HPP
#define BOOST_MPL11_LAMBDA_HPP

#include <boost/mpl11/bind.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/protect.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/trait/is_placeholder.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Expression>
struct lambda;

namespace lambda_detail {
    template <typename Expression>
    struct is_placeholder_expression
        : trait::is_placeholder<Expression>
    { };

    // Note: We can't use algorithms here because that would create a
    //       circular dependency.
    template <typename ...T>
    struct any_is_placeholder_expression : false_ { };

    template <typename Head, typename ...Tail>
    struct any_is_placeholder_expression<Head, Tail...>
        : or_<
            is_placeholder_expression<Head>,
            any_is_placeholder_expression<Tail...>
        >
    { };

    template <template <typename ...> class M, typename ...T>
    struct is_placeholder_expression<M<T...>>
        : or_<
            trait::is_placeholder<M<T...>>,
            any_is_placeholder_expression<T...>
        >
    { };

    template <typename Expression>
    struct contains_placeholder_expression : false_ { };

    template <template <typename ...> class M, typename ...T>
    struct contains_placeholder_expression<M<T...>>
        : any_is_placeholder_expression<T...>
    { };

    template <typename Expression>
    struct lambdaize {
        using type = Expression;
    };

    template <template <typename ...> class M, typename ...T>
    struct lambdaize<M<T...>> {
        using type = protect<
            bind<quote<M>, typename lambda<T>::type...>
        >;
    };
} // end namespace lambda_detail

template <typename Expression>
struct lambda
    :   if_<trait::is_placeholder<Expression>,
            Expression>::template
        else_if<lambda_detail::contains_placeholder_expression<Expression>,
            eval<lambda_detail::lambdaize<Expression>>>::template
        else_<Expression>
{ };
}}}

#endif // !BOOST_MPL11_LAMBDA_HPP
