/*!
 * @file
 * Defines `boost::mpl11::detail::std_equal`.
 */

#ifndef BOOST_MPL11_DETAIL_STD_EQUAL_HPP
#define BOOST_MPL11_DETAIL_STD_EQUAL_HPP

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns whether two iterator-delimited ranges are equal by comparing
     * their elements side-by-side.
     */
    template <
        typename F1, typename L1,
        typename F2, typename L2,
        bool = equal<F1, L1>::value
    >
    struct std_equal;

    template <
        typename F1, typename L1,
        typename F2, typename L2
    >
    struct std_equal<F1, L1, F2, L2, true>
        : equal<F2, L2>
    { };

    namespace std_equal_detail {
        template <typename F1, typename L1, typename F2, typename L2>
        struct lazy_next_step
            : std_equal<
                typename next<F1>::type, L1,
                typename next<F2>::type, L2
            >
        { };
    } // end namespace std_equal_detail

    template <typename F1, typename L1, typename F2, typename L2>
    struct std_equal<F1, L1, F2, L2, false>
        : and_<
            equal<typename deref<F1>::type, typename deref<F2>::type>,
            std_equal_detail::lazy_next_step<F1, L1, F2, L2>
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STD_EQUAL_HPP
