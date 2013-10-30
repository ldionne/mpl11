/*!
 * @file
 * Forward declares `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_FWD_COMPARABLE_HPP
#define BOOST_MPL11_FWD_COMPARABLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup comparison_operators Comparison operators
     * @ingroup intrinsics
     *
     * Intrinsics representing C++ comparison operators.
     *
     * Comparison operators form a general comparison system between
     * compatible metatypes. They are not exclusively meant for numeric
     * metatypes and other @ref datatypes such as `Couple`s do provide
     * some comparison operators when it makes sense.
     *
     * @note
     * Two metatypes are said to be compatible w.r.t. comparison operators if
     * it makes sense to compare them. For example, it makes sense to compare
     * two `Couple`s, but it might not make sense to compare a `Couple` with
     * an `IntegralConstant`.
     *
     * Comparison operators are more than mere metafunctions: they are full-
     * fledged boolean `IntegralConstant`s returning the result of the
     * comparison. Enforcing this convention has proven to increase the
     * usability of these operators. Because of this, when writing custom
     * comparison operators, one must make sure to provide a valid boolean
     * `IntegralConstant` instead of a simple metafunction returning a
     * boolean `IntegralConstant`.
     *
     * Unlike in normal C++, comparison operators may be chained (as seen
     * in mathematics and in Python). Therefore, for any comparison operator
     * `comp` and arguments `A0`, ..., `An`, the following are equivalent:
     *
            comp<A0, ..., An>
     *
     * and
     *
            and_<
                comp<A0, A1>,
                comp<A1, ...An>
            >
     *
     * @see `Comparable`, `Orderable`
     */

    /*!
     * @ingroup concepts
     *
     * Type implementing the `==` and `!=` C++ operators.
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `T`, `U`   | Compatible `Comparable`s
     *
     *
     * ## Valid expressions
     * | Expression               | Type
     * | ----------               | ----
     * | `mpl11::equal<T, U>`     | Boolean `IntegralConstant`
     * | `mpl11::not_equal<T, U>` | Boolean `IntegralConstant`
     */
    struct Comparable BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COMPARABLE_HPP
