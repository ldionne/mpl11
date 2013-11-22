/*!
 * @file
 * Defines `boost::mpl11::Couple`.
 */

#ifndef BOOST_MPL11_COUPLE_HPP
#define BOOST_MPL11_COUPLE_HPP

#include <boost/mpl11/fwd/couple.hpp>

// Required by the forward declaration.
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/orderable.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/second.hpp>


namespace boost { namespace mpl11 {
    template <typename C1, typename C2>
    struct Couple::less_impl
        : or_<
            less<first_t<C1>, first_t<C2>>,
            and_<
                not_<less<first_t<C2>, first_t<C1>>>,
                less<second_t<C1>, second_t<C2>>
            >
        >
    { };

    template <typename C1, typename C2>
    struct Couple::equal_impl
        : and_<
            equal<first_t<C1>, first_t<C2>>,
            equal<second_t<C1>, second_t<C2>>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUPLE_HPP
