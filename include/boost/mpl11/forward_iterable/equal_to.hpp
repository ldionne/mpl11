/*!
 * @file
 * Defines `boost::mpl11::ForwardIterable::equal_to`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERABLE_EQUAL_TO_HPP
#define BOOST_MPL11_FORWARD_ITERABLE_EQUAL_TO_HPP

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/forward_iterable/forward_iterable.hpp>


namespace boost { namespace mpl11 {
    //! @todo consider removing equal<> from the algorithms
    template <typename I1, typename I2>
    struct ForwardIterable::equal_to
        : equal<I1, I2> // use element-wise equality
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERABLE_EQUAL_TO_HPP
