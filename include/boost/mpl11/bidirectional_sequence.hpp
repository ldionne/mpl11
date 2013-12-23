/*!
 * @file
 * Defines `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/bidirectional_sequence.hpp>

#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/directional_sequence.hpp> // required by forward decl
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/prev.hpp>

#include <boost/mpl11/forward_sequence.hpp> // required by forward decl


namespace boost { namespace mpl11 {
    template <typename S>
    struct BidirectionalSequence::back_impl {
        static_assert(!is_empty<S>::value,
        "Attempt to use `back` on an empty sequence.");

        using type = deref_t<prev_t<end_t<S>>>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
