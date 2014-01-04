/*!
 * @file
 * Defines `boost::mpl11::empty_sequence`.
 */

#ifndef BOOST_MPL11_EMPTY_SEQUENCE_HPP
#define BOOST_MPL11_EMPTY_SEQUENCE_HPP

#include <boost/mpl11/fwd/empty_sequence.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct tag_of<empty_sequence> { using type = sequence_tag; };

    template <>
    struct sequence_traits<empty_sequence> {
        static constexpr bool has_O1_size = true;
        static constexpr bool has_O1_unpack = true;
        static constexpr bool is_finite = true;
    };

    template <>
    struct is_empty_impl<empty_sequence>
        : true_
    { };

    template <>
    struct length_impl<empty_sequence>
        : size_t<0>
    { };

    template <typename F>
    struct unpack_impl<empty_sequence, F> {
        using type = typename apply<F>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EMPTY_SEQUENCE_HPP
