/*!
 * @file
 * Defines `boost::mpl::bool_`.
 */

#ifndef BOOST_MPL11_BOOL_HPP
#define BOOST_MPL11_BOOL_HPP

#include <boost/mpl11/fwd/bool.hpp>

#include <boost/mpl11/boolean.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <bool B>
    struct class_of<bool_<B>> {
        struct type final : Boolean {
            template <typename>
            using not_impl = identity<bool_<!B>>;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BOOL_HPP
