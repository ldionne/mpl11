/*!
 * @file
 * Defines logical metafunctions.
 */

#ifndef BOOST_MPL11_LOGICAL_HPP
#define BOOST_MPL11_LOGICAL_HPP

#include <boost/mpl11/fwd/logical.hpp>

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace logical_detail {
        template <bool current, bool done>
        struct and_impl {
            template <typename ...>
            using result = bool_<current>;
        };

        template <>
        struct and_impl<true, false> {
            template <typename x, typename ...xs>
            using result = typename and_impl<
                (bool)x::type::value, sizeof...(xs) == 0
            >::template result<xs...>;
        };

        template <bool current, bool done>
        struct or_impl {
            template <typename ...>
            using result = bool_<current>;
        };

        template <>
        struct or_impl<false, false> {
            template <typename x, typename ...xs>
            using result = typename or_impl<
                (bool)x::type::value, sizeof...(xs) == 0
            >::template result<xs...>;
        };
    } // end namespace logical_detail

    template <typename ...xs>
    struct and_ :
        logical_detail::and_impl<true, false>::
        template result<xs...>
    { };

    template <typename ...xs>
    struct or_ :
        logical_detail::or_impl<false, false>::
        template result<xs...>
    { };

    template <> struct and_<> : true_ { };
    template <> struct or_<>  : false_ { };

    template <typename b>
    struct not_
        : bool_<!b::type::value>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LOGICAL_HPP
