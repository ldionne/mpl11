/*!
 * @file
 * Defines `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_EQUAL_HPP
#define BOOST_MPL11_EQUAL_HPP

#include <boost/mpl11/fwd/equal.hpp>

#include <boost/mpl11/detail/comparison_operator.hpp>
#include <boost/mpl11/detail/default_class.hpp>
#include <boost/mpl11/detail/is_same.hpp>


namespace boost { namespace mpl11 {
    template <typename U, typename V>
    struct detail::default_class::equal_impl
        : detail::is_same<U, V>
    { };
}} // end namespace boost::mpl11

BOOST_MPL11_DEFINE_COMPARISON_OPERATOR(equal, equal_impl)

#endif // !BOOST_MPL11_EQUAL_HPP
