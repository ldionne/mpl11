/*!
 * @file
 * Defines `boost::mpl11::Orderable::less`.
 */

#ifndef BOOST_MPL11_ORDERABLE_LESS_HPP
#define BOOST_MPL11_ORDERABLE_LESS_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/orderable/orderable.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y>
    struct Orderable::less
        : detail::not_implemented<less<X, Y>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_LESS_HPP
