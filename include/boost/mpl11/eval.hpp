/*!
 * @file
 * This file defines `boost::mpl11::eval`.
 */

#ifndef BOOST_MPL11_EVAL_HPP
#define BOOST_MPL11_EVAL_HPP

#include <boost/mpl11/protect.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
    template <typename Expression>
    struct eval {
        using type = Expression;
    };

    template <template <typename ...> class Expression, typename ...T>
    struct eval<Expression<T...>> {
        using type = Expression<typename eval<T>::type...>;
    };

    template <typename Metafunction>
    struct eval<eval<Metafunction>>
        : eval<Metafunction>::type
    { };

    template <typename Expression>
    struct eval<protect<Expression>> {
        using type = protect<Expression>;
    };
}}}

#endif // !BOOST_MPL11_EVAL_HPP
