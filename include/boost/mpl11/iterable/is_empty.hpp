/*!
 * @file
 * Defines `boost::mpl11::Iterable::is_empty`.
 */

#ifndef BOOST_MPL11_ITERABLE_IS_EMPTY_HPP
#define BOOST_MPL11_ITERABLE_IS_EMPTY_HPP

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct Iterable::is_empty
        : equal_to<
            typename begin<I>::type,
            typename end<I>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_IS_EMPTY_HPP
