/*!
 * @file
 * Defines `boost::mpl11::not_equal_to`.
 */

#ifndef BOOST_MPL11_NOT_EQUAL_TO_HPP
#define BOOST_MPL11_NOT_EQUAL_TO_HPP

#include <boost/mpl11/fwd/not_equal_to.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename ...Tn>
    struct dispatch<tag::not_equal_to, T1, T2, Tn...>
        : and_<
            not_equal_to<T1, T2>,
            not_equal_to<T2, Tn...>
        >
    { };

    template <typename T1, typename T2>
    struct dispatch<tag::not_equal_to, T1, T2>
        : not_<equal_to<T1, T2>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NOT_EQUAL_TO_HPP
