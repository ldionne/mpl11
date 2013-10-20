/*!
 * @file
 * Defines `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/less.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/object.hpp>


namespace boost { namespace mpl11 {
    struct Orderable : Object {
        // less<> is not implemented

        template <typename Self, typename Other>
        struct greater
            : less<Other, Self>
        { };

        template <typename Self, typename Other>
        struct greater_equal
            : not_<typename less<Self, Other>::type>
        { };

        template <typename Self, typename Other>
        struct less_equal
            : not_<typename less<Other, Self>::type>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_HPP
