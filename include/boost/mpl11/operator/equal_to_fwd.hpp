/*!
 * @file
 * Forward declares `boost::mpl11::equal_to`.
 */

#ifndef BOOST_MPL11_EQUAL_TO_FWD_HPP
#define BOOST_MPL11_EQUAL_TO_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct equal_to; }

    /*!
     * @ingroup comparison_operators
     *
     * Returns whether `T1 == T2 == ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * When more than two arguments are provided, as described in
     * @ref comparison_operators. Otherwise:
     * - If `T1` and `T2` are @ref IntegralConstant "Integral Constants",
     *   equivalent to `identity<bool_<T1::value == T2::value>>`.
     * - If `T1` and `T2` are @ref AssociativeSequence "Associative Sequences",
     *   equivalent to checking whether both sequences have the same keys
     *   mapping to the same values.
     * - If `T1` and `T2` are @ref ForwardSequence "Forward Sequences",
     *   equivalent to `algorithm::equal<T1, T2>`.
     * - Otherwise, equivalent to
     *   `identity<bool_<std::is_same<T1, T2>::value>>`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct equal_to
        : dispatch<tag::equal_to, T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQUAL_TO_FWD_HPP
