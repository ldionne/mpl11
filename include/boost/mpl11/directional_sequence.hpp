/*!
 * @file
 * Defines `boost::mpl11::DirectionalSequence`.
 */

#ifndef BOOST_MPL11_DIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_DIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/directional_sequence.hpp>

// Required by the forward declaration.
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/sequence.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/is_empty.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct DirectionalSequence::front_impl {
        static_assert(!is_empty<S>::value,
        "Attempt to use `front` on an empty sequence.");

        using type = typename deref<typename begin<S>::type>::type;
    };

    template <typename S1, typename S2>
    struct DirectionalSequence::equal_impl
        : detail::std_equal<
            typename begin<S1>::type, typename end<S1>::type,
            typename begin<S2>::type, typename end<S2>::type
        >
    { };

    template <typename S1, typename S2>
    struct DirectionalSequence::less_impl
        : detail::lexicographical_compare<
            typename begin<S1>::type, typename end<S1>::type,
            typename begin<S2>::type, typename end<S2>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DIRECTIONAL_SEQUENCE_HPP
