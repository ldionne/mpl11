/*!
 * @file
 * Defines `boost::mpl11::Orderable::greater_equal`.
 */

#ifndef BOOST_MPL11_ORDERABLE_GREATER_EQUAL_HPP
#define BOOST_MPL11_ORDERABLE_GREATER_EQUAL_HPP

#include <boost/mpl11/less.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/orderable/orderable.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y>
    struct Orderable::greater_equal
        : not_<less<X, Y>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_GREATER_EQUAL_HPP
