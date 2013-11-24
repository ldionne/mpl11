/*!
 * @file
 * Defines `boost::mpl11::detail::tp_conditional`.
 */

#ifndef BOOST_MPL11_DETAIL_TP_CONDITIONAL_HPP
#define BOOST_MPL11_DETAIL_TP_CONDITIONAL_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Provides a nested template alias named `type`, which is an alias to
     * either `Then` or `Else` depending on the value of `Condition`.
     */
    template <
        bool Condition,
        template <typename ...> class Then,
        template <typename ...> class Else>
    struct tp_conditional;

    template <
        template <typename ...> class Then,
        template <typename ...> class Else>
    struct tp_conditional<true, Then, Else> {
        template <typename ...Args>
        using type = Then<Args...>;
    };

    template <
        template <typename ...> class Then,
        template <typename ...> class Else>
    struct tp_conditional<false, Then, Else> {
        template <typename ...Args>
        using type = Else<Args...>;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TP_CONDITIONAL_HPP
