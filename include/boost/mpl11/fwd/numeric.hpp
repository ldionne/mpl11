/*!
 * @file
 * Forward declares `boost::mpl11::Numeric`.
 */

#ifndef BOOST_MPL11_FWD_NUMERIC_HPP
#define BOOST_MPL11_FWD_NUMERIC_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Numeric Numeric
     *
     * Typeclass providing basic numeric capabilities.
     *
     * `Numeric`s must satisfy the following law:
     *
            abs(x) * sign(x) == x
     *
     *
     * ### Methods
     * `plus`, `minus`, `times`, `negate`, `abs` and `sign`.
     *
     * The `plus`, `minus` and `times` methods can be invoked with more than
     * two arguments. In that case, the methods are left-associative like
     * their C++ counterpart. Specifically, `method<T1, ..., Tn>` is
     * equivalent to `method<method<T1, T2>::%type, ..., Tn>`, and
     * `method<T1, T2>` uses the usual tag dispatching technique.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Numeric;

    //! Returns the sum of the given objects (`T1 + T2 + ...Tn`).
    template <typename T1, typename T2, typename ...Tn>
    struct plus;

    template <typename T1, typename T2, typename ...Tn>
    using plus_t = typename plus<T1, T2, Tn...>::type;


    //! Returns the subtraction of the given objects (`T1 - T2 - ...Tn`).
    template <typename T1, typename T2, typename ...Tn>
    struct minus;

    template <typename T1, typename T2, typename ...Tn>
    using minus_t = typename minus<T1, T2, Tn...>::type;


    //! Returns the product of the given objects (`T1 * T2 * ...Tn`).
    template <typename T1, typename T2, typename ...Tn>
    struct times;

    template <typename T1, typename T2, typename ...Tn>
    using times_t = typename times<T1, T2, Tn...>::type;


    //! Returns the unary negation of the given object (`-N`).
    template <typename N>
    struct negate;

    template <typename N>
    using negate_t = typename negate<N>::type;


    //! Returns the absolute value of the given object.
    template <typename N>
    struct abs;

    template <typename N>
    using abs_t = typename abs<N>::type;


    /*!
     * Returns the sign of the given object.
     *
     * For real numbers, the sign is either `-1` (negative), `0` (zero) or
     * `1` (positive).
     */
    template <typename N>
    struct sign;

    template <typename N>
    using sign_t = typename sign<N>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NUMERIC_HPP
