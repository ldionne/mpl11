/*!
 * @file
 * Defines `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_ORDERABLE_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/less.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y>
    struct Orderable::less_equal_impl
        : not_<less<Y, X>>
    { };

    template <typename X, typename Y>
    struct Orderable::greater_impl
        : less<Y, X>
    { };

    template <typename X, typename Y>
    struct Orderable::greater_equal_impl
        : not_<less<X, Y>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_ORDERABLE_HPP
