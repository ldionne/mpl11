/*!
 * @file
 * Defines `boost::mpl11::Type`.
 */

#ifndef BOOST_MPL11_TYPE_HPP
#define BOOST_MPL11_TYPE_HPP

#include <boost/mpl11/fwd/type.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename X, typename Y>
    struct Type::equal_impl
        : detail::is_same<X, Y>
    { };

    template <typename X, typename Y>
    struct Type::not_equal_impl
        : not_<detail::is_same<X, Y>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TYPE_HPP
