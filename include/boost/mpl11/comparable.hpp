/*!
 * @file
 * Defines `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/object.hpp>


namespace boost { namespace mpl11 {
    struct Comparable : Object {
        template <typename Self, typename Other>
        struct equal_to
            : detail::is_same<Self, Other>
        { };

        template <typename Self, typename Other>
        struct not_equal_to
            : not_<typename equal_to<Self, Other>::type>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
