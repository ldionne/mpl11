/*!
 * @file
 * Defines `boost::mpl11::detail::comparison_operator`.
 */

#ifndef BOOST_MPL11_DETAIL_COMPARISON_OPERATOR_HPP
#define BOOST_MPL11_DETAIL_COMPARISON_OPERATOR_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Provides the common behavior of comparison operators.
     *
     * Each comparison method should specialize the binary case (and only
     * that case) to dispatch to the right typeclass.
     *
     *
     * @note
     * We use this mechanism instead of specializing the comparison methods
     * for two arguments because that could make some user-defined
     * specializations ambiguous.
     */
    template <bool Binary, template <typename ...> class Operator>
    struct comparison_operator;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/and.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <template <typename ...> class Operator>
    struct comparison_operator<false, Operator> {
        template <typename T1, typename T2, typename ...Tn>
        using apply = and_<Operator<T1, T2>, Operator<T2, Tn...>>;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_COMPARISON_OPERATOR_HPP
