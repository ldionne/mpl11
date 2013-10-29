/*!
 * @file
 * Defines `boost::mpl11::Couple`.
 */

#ifndef BOOST_MPL11_COUPLE_HPP
#define BOOST_MPL11_COUPLE_HPP

#include <boost/mpl11/fwd/couple.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/second.hpp>


namespace boost { namespace mpl11 {
    struct Couple : Comparable, Orderable {
        //! This operation must be provided by the user.
        template <typename Pair>
        struct first_impl;

        //! This operation must be provided by the user.
        template <typename Pair>
        struct second_impl;

        //! Performs a lexicographical comparison of the two pairs.
        template <typename Pair1, typename Pair2>
        class less_impl {
            using First1 = typename first<Pair1>::type;
            using First2 = typename first<Pair2>::type;

            using Second1 = typename second<Pair1>::type;
            using Second2 = typename second<Pair2>::type;

        public:
            using type = typename or_<
                less<First1, First2>,
                and_<
                    not_<less<First2, First1>>,
                    less<Second1, Second2>
                >
            >::type;
        };

        //! Performs a memberwise comparison of the two pairs.
        template <typename Pair1, typename Pair2>
        struct equal_impl
            : and_<
                equal<
                    typename first<Pair1>::type,
                    typename first<Pair2>::type
                >,
                equal<
                    typename second<Pair1>::type,
                    typename second<Pair2>::type
                >
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUPLE_HPP
