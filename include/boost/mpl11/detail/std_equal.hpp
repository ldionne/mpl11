/*!
 * @file
 * Defines `boost::mpl11::detail::std_equal`.
 */

#ifndef BOOST_MPL11_DETAIL_STD_EQUAL_HPP
#define BOOST_MPL11_DETAIL_STD_EQUAL_HPP

#include <boost/mpl11/fwd/forward_sequence.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns whether two sequences are equal by comparing their
     * elements side-by-side.
     *
     * @todo implement this with fold
     */
    template <
        typename S1, typename S2,
        bool = is_empty<S1>::value,
        bool = is_empty<S2>::value
    >
    struct std_equal;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/and.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename S1, typename S2, bool, bool>
    struct std_equal
        : false_
    { };

    template <typename S1, typename S2>
    struct std_equal<S1, S2, true, true>
        : true_
    { };

    template <typename S1, typename S2>
    struct std_equal<S1, S2, false, false>
        : and_<
            equal<head_t<S1>, head_t<S2>>,
            std_equal<tail_t<S1>, tail_t<S2>>
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STD_EQUAL_HPP
