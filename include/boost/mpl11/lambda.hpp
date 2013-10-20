/*!
 * @file
 * Defines `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_LAMBDA_HPP
#define BOOST_MPL11_LAMBDA_HPP

#include <boost/mpl11/fwd/lambda.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/is_placeholder_expression.hpp>
#include <boost/mpl11/metafunction_class.hpp>


namespace boost { namespace mpl11 {
    namespace lambda_detail {
        template <bool IsPlaceholder, typename Body, typename ...Args>
        struct substitute;

        template <typename Body, typename ...Args>
        struct substitute<true, Body, Args...>
            : apply<Body, Args...>
        { };

        template <typename Body, typename ...Args>
        struct substitute<false, Body, Args...>
            : Body
        { };

        template <
            template <typename ...> class Body,
            typename ...T,
            typename ...Args
        >
        struct substitute<false, Body<T...>, Args...>
            : Body<
                typename if_<typename is_placeholder<T>::type,
                    apply<T, Args...>
                >::template else_if<is_placeholder_expression<T>,
                    substitute<false, T, Args...>
                >::template else_<
                    identity<T>
                >::type::type...
            >
        { };
    } // end namespace lambda_detail

    template <typename Body>
    struct lambda {
        using mpl_class = MetafunctionClass;

        template <typename ...Args>
        struct apply
            : lambda_detail::substitute<
                is_placeholder<Body>::type::value, Body, Args...
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LAMBDA_HPP
