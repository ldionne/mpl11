/*!
 * @file
 * Defines `boost::mpl11::detail::lexicographical_compare`.
 */

#ifndef BOOST_MPL11_DETAIL_LEXICOGRAPHICAL_COMPARE_HPP
#define BOOST_MPL11_DETAIL_LEXICOGRAPHICAL_COMPARE_HPP

#include <boost/mpl11/fwd/equal.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Performs a lexicographical ordering of the two iterator-delimited
     * ranges.
     */
    template <
        typename F1, typename L1,
        typename F2, typename L2,
        bool = equal<F1, L1>::value,
        bool = equal<F2, L2>::value
    >
    struct lexicographical_compare;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/and.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename F1, typename L1, typename F2, typename L2, bool, bool>
    struct lexicographical_compare
        : false_
    { };

    // [F1, L1) is shorter than [F2, L2)
    template <typename F1, typename L1, typename F2, typename L2>
    struct lexicographical_compare<F1, L1, F2, L2, true, false>
        : true_
    { };

    namespace lexicographical_compare_detail {
        template <typename F1, typename L1, typename F2, typename L2>
        struct lazy_next_step
            : lexicographical_compare<
                next_t<F1>, L1,
                next_t<F2>, L2
            >
        { };
    } // end namespace lexicographical_compare_detail

    // (*F1 < *F2) or (*F1 == *F2 and compare the rest)
    template <typename F1, typename L1, typename F2, typename L2>
    struct lexicographical_compare<F1, L1, F2, L2, false, false>
        : or_<
            less<deref_t<F1>, deref_t<F2>>,
            and_<
                not_<less<deref_t<F2>, deref_t<F1>>>,
                lexicographical_compare_detail::lazy_next_step<F1, L1, F2, L2>
            >
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_LEXICOGRAPHICAL_COMPARE_HPP
