/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_AND_HPP
#define BOOST_MPL11_AND_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 {
    namespace and_detail {
        template <bool F1, typename ...Fn>
        struct and_impl;

        template <bool F1>
        struct and_impl<F1> : bool_<F1> { };

        template <typename F2, typename ...Fn>
        struct and_impl<false, F2, Fn...> : false_ { };

        template <typename F2, typename ...Fn>
        struct and_impl<true, F2, Fn...>
            : and_impl<F2::type::value, Fn...>
        { };
    } // end namespace and_detail

    /*!
     * Returns the result of short-circuit _logical and_ on its arguments.
     *
     * Returns `false_` if either `F1::type::value`, `F2::type::value`, or
     * `Fn::type::value...` evaluates to `false`, and `true_` otherwise.
     * Lazy left-to-right evaluation is guaranteed.
     *
     * @tparam F1, F2, Fn...
     *         Nullary boolean metafunctions that are lazily evaluated from
     *         left to right.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : and_detail::and_impl<F1::type::value, F2, Fn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AND_HPP
