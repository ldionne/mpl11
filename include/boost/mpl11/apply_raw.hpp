/*!
 * @file
 * This file defines `boost::mpl11::apply_raw`.
 */

#ifndef BOOST_MPL11_APPLY_RAW_HPP
#define BOOST_MPL11_APPLY_RAW_HPP

#include <boost/mpl11/detail/nested_apply.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
    template <typename M, typename ...Args>
    struct apply_raw
        : detail::nested_apply<M, Args...>::type
    { };
}}}

#endif // !BOOST_MPL11_APPLY_RAW_HPP
