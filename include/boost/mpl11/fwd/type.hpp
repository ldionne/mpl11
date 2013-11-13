/*!
 * @file
 * Forward declares `boost::mpl11::Type`.
 */

#ifndef BOOST_MPL11_FWD_TYPE_HPP
#define BOOST_MPL11_FWD_TYPE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * Any type.
     *
     * `Type` is the default class for all C++ types. It provides defaults
     * for some basic operations like comparison.
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `T`, `U`   | Arbitrary `Type`s
     *
     *
     * ## Valid expressions
     * | Expression               | %Type
     * | ----------               | ----
     * | `mpl11::equal<T, U>`     | Boolean `IntegralConstant`
     * | `mpl11::not_equal<T, U>` | Boolean `IntegralConstant`
     */
    struct Type {
        //! Returns whether `X` is the same type as `Y`.
        template <typename X, typename Y>
        struct equal_impl;

        //! Returns whether `X` is a type different from `Y`.
        template <typename X, typename Y>
        struct not_equal_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TYPE_HPP
