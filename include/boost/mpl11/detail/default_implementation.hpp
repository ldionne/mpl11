/*!
 * @file
 * This file defines `boost::mpl11::detail::default_implementation`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_IMPLEMENTATION_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_IMPLEMENTATION_HPP

#include <boost/mpl11/functional/apply.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
    template <typename Operation, typename ...Args>
    struct default_implementation
        : apply<typename Operation::mpl11::default_implementation, Args...>
    { };
}}}}

#endif // !BOOST_MPL11_DETAIL_DEFAULT_IMPLEMENTATION_HPP
