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
    struct Orderable {
        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct less_impl;

        //! Equivalent to `not_<mpl11::less<Y, X>>`.
        template <typename X, typename Y>
        struct less_equal_impl
            : not_<less<Y, X>>
        { };

        //! Equivalent to `mpl11::less<Y, X>`.
        template <typename X, typename Y>
        struct greater_impl
            : less<Y, X>
        { };

        //! Equivalent to `not_<mpl11::less<X, Y>>`.
        template <typename X, typename Y>
        struct greater_equal_impl
            : not_<less<X, Y>>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_ORDERABLE_HPP
