/*!
 * @file
 * Defines `boost::mpl11::Iterable::end`.
 */

#ifndef BOOST_MPL11_ITERABLE_END_HPP
#define BOOST_MPL11_ITERABLE_END_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct Iterable::end
        : detail::not_implemented<end<I>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_END_HPP
