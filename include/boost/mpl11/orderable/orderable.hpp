/*!
 * @file
 * Defines `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_ORDERABLE_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/comparable/comparable.hpp>


namespace boost { namespace mpl11 {
    struct Orderable : Comparable {
        template <typename X, typename Y>
        struct less;

        template <typename X, typename Y>
        struct less_equal;

        template <typename X, typename Y>
        struct greater;

        template <typename X, typename Y>
        struct greater_equal;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_ORDERABLE_HPP
