/*!
 * @file
 * Defines `boost::mpl11::sequence_traits`.
 */

#ifndef BOOST_MPL11_SEQUENCE_TRAITS_HPP
#define BOOST_MPL11_SEQUENCE_TRAITS_HPP

#include <boost/mpl11/fwd/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct sequence_traits {
        static constexpr bool has_O1_length = false;
        static constexpr bool has_O1_unpack = false;
        static constexpr bool is_finite = false;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_TRAITS_HPP
