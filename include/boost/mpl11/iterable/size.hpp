/*!
 * @file
 * Defines `boost::mpl11::Iterable::size`.
 */

#ifndef BOOST_MPL11_ITERABLE_SIZE_HPP
#define BOOST_MPL11_ITERABLE_SIZE_HPP

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct Iterable::size
        : distance<
            typename begin<I>::type,
            typename end<I>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SIZE_HPP
