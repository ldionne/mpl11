/*!
 * @file
 * Defines `boost::mpl11::detail::always_false`.
 */

#ifndef BOOST_MPL11_DETAIL_ALWAYS_FALSE_HPP
#define BOOST_MPL11_DETAIL_ALWAYS_FALSE_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename ...>
    struct always_false
        : false_
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_ALWAYS_FALSE_HPP
