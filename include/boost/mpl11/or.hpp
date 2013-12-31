/*!
 * @file
 * Defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OR_HPP
#define BOOST_MPL11_OR_HPP

#include <boost/mpl11/fwd/or.hpp>

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace or_detail {
        template <bool ValueOfLast, bool WeAreDone>
        struct or_impl;

        template <>
        struct or_impl<false, false> {
            template <typename F1, typename ...Fn>
            using apply = typename or_impl<
                            static_cast<bool>(F1::type::value),
                            sizeof...(Fn) == 0
                          >::template apply<Fn...>;
        };

        template <>
        struct or_impl<false, true> {
            template <typename ...Fn>
            using apply = false_;
        };

        template <bool WeAreDone>
        struct or_impl<true, WeAreDone> {
            template <typename ...>
            using apply = true_;
        };
    } // end namespace or_detail

    //! @todo Use a generic fold instead.
    template <typename ...Fn>
    struct or_
        : or_detail::or_impl<false, false>::template apply<Fn...>
    { };

    template <>
    struct or_<>
        : false_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OR_HPP
