/*!
 * @file
 * Forward declares `boost::mpl11::Arithmetic`.
 */

#ifndef BOOST_MPL11_FWD_ARITHMETIC_HPP
#define BOOST_MPL11_FWD_ARITHMETIC_HPP

#include <boost/mpl11/detail/methods.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Arithmetic Arithmetic
     *
     * The `Arithmetic` typeclass is used for datatypes supporting the usual
     * arithmetic operations.
     *
     *
     * ### Methods
     * `add`, `subtract`, `modulo`, `divide` and `multiply`.
     *
     * All of these methods except `modulo` can be invoked with more than two
     * arguments. In that case, the methods are left-associative like their
     * C++ equivalent. Specifically, `method<T1, ..., Tn>` is equivalent to
     * `method<method<T1, T2>::%type, ..., Tn>`, and `method<T1, T2>` uses
     * the usual tag dispatching technique.
     *
     * ### Minimal complete definition
     * All of the above methods.
     *
     *
     * @todo
     * Implement multiple arguments as documented.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Arithmetic;

#ifndef BOOST_MPL11_DOXYGEN_INVOKED
    namespace unchecked {
#endif

    //! Returns the sum of the given objects (`T1 + T2 + ...Tn`).
    template <typename T1, typename T2> struct add;

    //! Returns the subtraction of the given objects (`T1 - T2 - ...Tn`).
    template <typename T1, typename T2> struct subtract;

    //! Returns the product of the given objects (`T1 * T2 * ...Tn`).
    template <typename T1, typename T2> struct multiply;

    //! Returns the division of the given objects (`T1 / T2 / ...Tn`).
    template <typename T1, typename T2> struct divide;

    //! Returns the modulo of the given objects (`T1 % T2`).
    template <typename T1, typename T2> struct modulo;

#ifndef BOOST_MPL11_DOXYGEN_INVOKED
    } // end namespace unchecked

    namespace checked {
        using unchecked::add;
        using unchecked::subtract;
        using unchecked::multiply;
        using unchecked::divide;
        using unchecked::modulo;
    }

    using methods::add;
    using methods::subtract;
    using methods::multiply;
    using methods::divide;
    using methods::modulo;
#endif

    template <typename T1, typename T2>
    using add_t = typename add<T1, T2>::type;

    template <typename T1, typename T2>
    using subtract_t = typename subtract<T1, T2>::type;

    template <typename T1, typename T2>
    using multiply_t = typename multiply<T1, T2>::type;

    template <typename T1, typename T2>
    using divide_t = typename divide<T1, T2>::type;

    template <typename T1, typename T2>
    using modulo_t = typename modulo<T1, T2>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARITHMETIC_HPP
