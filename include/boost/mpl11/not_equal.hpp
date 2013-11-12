/*!
 * @file
 * Defines `boost::mpl11::not_equal`.
 */

#ifndef BOOST_MPL11_NOT_EQUAL_HPP
#define BOOST_MPL11_NOT_EQUAL_HPP

#include <boost/mpl11/fwd/not_equal.hpp>

#include <boost/mpl11/detail/comparison_operator.hpp>
#include <boost/mpl11/detail/default_class.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename U, typename V>
    struct detail::default_class::not_equal_impl
        : not_<detail::is_same<U, V>>
    { };
}} // end namespace boost::mpl11

BOOST_MPL11_DEFINE_COMPARISON_OPERATOR(not_equal, not_equal_impl)

#endif // !BOOST_MPL11_NOT_EQUAL_HPP
