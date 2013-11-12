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
            less<
                typename first<C1>::type,
                typename first<C2>::type
            >,
            and_<
                not_<
                    less<
                        typename first<C2>::type,
                        typename first<C1>::type>
                >,
                less<
                    typename second<C1>::type,
                    typename second<C2>::type
                >
            >
        >
    { };

    template <typename C1, typename C2>
    struct Couple::equal_impl
        : and_<
            equal<
                typename first<C1>::type,
                typename first<C2>::type
            >,
            equal<
                typename second<C1>::type,
                typename second<C2>::type
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUPLE_HPP
