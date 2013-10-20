/*!
 * @file
 * Defines `boost::mpl11::not_equal_to`.
 */

#ifndef BOOST_MPL11_NOT_EQUAL_TO_HPP
#define BOOST_MPL11_NOT_EQUAL_TO_HPP

#include <boost/mpl11/fwd/not_equal_to.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename A, typename B, typename ...C>
    struct not_equal_to
        : and_<
            typename not_equal_to<A, B>::type,
            not_equal_to<B, C...>
        >
    { };

    template <typename A, typename B>
    struct not_equal_to
        : class_<A>::type::template not_equal_to<A, B>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NOT_EQUAL_TO_HPP
