/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_AND_HPP
#define BOOST_MPL11_AND_HPP

#include <boost/mpl11/fwd/and.hpp>

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace and_detail {
        template <bool ValueOfLast, bool WeAreDone>
        struct and_impl;

        template <>
        struct and_impl<true, false> {
            template <typename F1, typename ...Fn>
            using apply = typename and_impl<
                            F1::type::value, sizeof...(Fn) == 0
                          >::template apply<Fn...>;
        };

        template <>
        struct and_impl<true, true> {
            template <typename ...Fn>
            using apply = true_;
        };

        template <bool WeAreDone>
        struct and_impl<false, WeAreDone> {
            template <typename ...>
            using apply = false_;
        };
    } // end namespace and_detail

    //! @todo Use a generic fold instead.
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : and_detail::and_impl<F1::type::value, false>::
            template apply<F2, Fn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AND_HPP
