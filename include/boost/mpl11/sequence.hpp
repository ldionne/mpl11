/*!
 * @file
 * Defines `boost::mpl11::Sequence`.
 */

#ifndef BOOST_MPL11_SEQUENCE_HPP
#define BOOST_MPL11_SEQUENCE_HPP

#include <boost/mpl11/fwd/sequence.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct Sequence::size_impl
        : distance<
            typename begin<S>::type,
            typename end<S>::type
        >
    { };

    template <typename S>
    struct Sequence::is_empty_impl
        : equal<
            typename begin<S>::type,
            typename end<S>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_HPP
