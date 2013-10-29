/*!
 * @file
 * Defines `boost::mpl11::detail::conditional`.
 */

#ifndef BOOST_MPL11_DETAIL_CONDITIONAL_HPP
#define BOOST_MPL11_DETAIL_CONDITIONAL_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns one of two types depending on a condition.
     *
     * Specifically, returns `Then` if `Cond` is `true` and `Else` otherwise.
     */
    template <bool Cond, typename Then, typename Else>
    struct conditional {
        using type = Then;
    };

    template <typename Then, typename Else>
    struct conditional<false, Then, Else> {
        using type = Else;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_CONDITIONAL_HPP
