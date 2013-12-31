/*!
 * @file
 * Defines `boost::mpl11::detail::lexicographical_compare`.
 */

#ifndef BOOST_MPL11_DETAIL_LEXICOGRAPHICAL_COMPARE_HPP
#define BOOST_MPL11_DETAIL_LEXICOGRAPHICAL_COMPARE_HPP

#include <boost/mpl11/fwd/is_empty.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Performs a lexicographical ordering of the two sequences.
     *
     *
     * @todo implement this with fold
     */
    template <typename S1, typename S2,
        bool = is_empty<S1>::value,
        bool = is_empty<S2>::value
    >
    struct lexicographical_compare;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/and.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/tail.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename S1, typename S2, bool, bool>
    struct lexicographical_compare
        : false_
    { };

    // S1 is shorter than S2
    template <typename S1, typename S2>
    struct lexicographical_compare<S1, S2, true, false>
        : true_
    { };

    // (head(S1) < head(S2)) or (head(S1) == head(S2) and compare the rest)
    template <typename S1, typename S2>
    struct lexicographical_compare<S1, S2, false, false>
        : or_<
            less<head_t<S1>, head_t<S2>>,
            and_<
                not_<less<head_t<S2>, head_t<S1>>>,
                lexicographical_compare<tail_t<S1>, tail_t<S2>>
            >
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_LEXICOGRAPHICAL_COMPARE_HPP
