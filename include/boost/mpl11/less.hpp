/*!
 * @file
 * Defines `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_LESS_HPP
#define BOOST_MPL11_LESS_HPP

#include <boost/mpl11/fwd/less.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct less
        : and_<
            typename less<A, B>::type,
            less<B, C...>
        >
    { };

    template <typename A, typename B>
    struct less<A, B>
        : class_<A>::type::template less<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LESS_HPP
