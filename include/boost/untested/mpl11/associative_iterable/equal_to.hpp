/*!
 * @file
 * Defines `boost::mpl11::AssociativeIterable::equal_to`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_ITERABLE_EQUAL_TO_HPP
#define BOOST_MPL11_ASSOCIATIVE_ITERABLE_EQUAL_TO_HPP

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/associative_iterable/associative_iterable.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
    namespace assoc_detail {
        template <typename T1, typename T2>
        struct lazy_equal_to
            : equal_to<typename T1::type, typename T2::type>
        { };
    } // end namespace assoc_detail

    template <typename I1, typename I2>
    struct AssociativeIterable::equal_to {
    private:
        using Last1 = typename end<I1>::type;

        template <
            typename First1,
            bool = equal_to<First1, Last1>::type::value
        >
        struct impl;

        template <typename First1>
        struct impl<First1, true>
            : identity<true_>
        { };

        template <typename First1>
        struct impl<First1, false> {
            using Element = typename deref<First1>::type;
            using Key = typename key_of<I1, Element>::type;

            using type = typename and_<
                has_key<I2, Key>,
                assoc_detail::lazy_equal_to<
                    value_of<I1, Element>,
                    at<I2, Key>
                >
            >::type;
        };

    public:
        using type = typename and_<
            equal_to<
                typename size<I1>::type,
                typename size<I2>::type
            >,
            impl<typename begin<I1>::type>
        >::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_ITERABLE_EQUAL_TO_HPP
