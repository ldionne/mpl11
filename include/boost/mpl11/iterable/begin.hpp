/*!
 * @file
 * Defines `boost::mpl11::Iterable::begin`.
 */

#ifndef BOOST_MPL11_ITERABLE_BEGIN_HPP
#define BOOST_MPL11_ITERABLE_BEGIN_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct Iterable::begin
        : detail::not_implemented<begin<I>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_BEGIN_HPP
