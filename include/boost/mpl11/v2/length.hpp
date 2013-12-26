/*!
 * @file
 * Defines `boost::mpl11::length`.
 */

#ifndef BOOST_MPL11_LENGTH_HPP
#define BOOST_MPL11_LENGTH_HPP

#include <boost/mpl11/v2/fwd/length.hpp>

#include <boost/mpl11/v2/fwd/finite_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct length
        : FiniteSequence<typename tag_of<S>::type>::template length_impl<S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LENGTH_HPP
