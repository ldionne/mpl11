/*!
 * @file
 * Defines `boost::mpl11::unpack`.
 */

#ifndef BOOST_MPL11_UNPACK_HPP
#define BOOST_MPL11_UNPACK_HPP

#include <boost/mpl11/v2/fwd/unpack.hpp>

#include <boost/mpl11/v2/fwd/finite_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S, typename F>
    struct unpack
        : FiniteSequence<typename tag_of<S>::type>::template unpack_impl<S, F>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_UNPACK_HPP
