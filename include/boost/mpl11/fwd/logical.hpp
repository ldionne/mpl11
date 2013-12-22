/*!
 * @file
 * Forward declares `boost::mpl11::Logical`.
 */

#ifndef BOOST_MPL11_FWD_LOGICAL_HPP
#define BOOST_MPL11_FWD_LOGICAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @defgroup logical_operators Logical operators
     * @ingroup intrinsics
     *
     * Intrinsics representing C++ logical operators.
     *
     * Logical operators are a bit special because they are required to
     * perform short-circuit evaluation whenever possible. As argument, they
     * expect metafunctions returning `Logical`s instead of expecting straight
     * `Logical`s. Whenever the evaluation of one argument allows the operator
     * to conclude, subsequent arguments are not evaluated. Note that
     * evaluation is made left-to-right, like one would expect.
     *
     * However, custom implementations of logical operators are called with
     * different conventions documented in each operator.
     *
     * `and_` and `or_` can be passed more than two arguments. Like in
     * standard C++, these operators are left-associative. Therefore, the
     * following are equivalent:
     *
            logical_op<A0, ..., An>
     *
     * and
     *
            logical_op<
                A0,
                logical_op<A1, ..., An>
            >
     *
     * where `logical_op` is either `and_` or `or_`.
     *
     * @see `Logical`
     */

    /*!
     * @ingroup concepts
     *
     * Type implementing C++ logical operators.
     *
     *
     * ## Notation
     * | Expression      | Description
     * | ----------      | -----------
     * | `A0`, ..., `An` | Arbitrary metafunctions returning `Logical`s
     *
     *
     * ## Valid expressions
     * | Expression          | Type
     * | ----------          | ----
     * | `not_<A0>`          | Boolean `Integral`
     * | `and_<A0, ..., An>` | `Metafunction`
     * | `or_<A0, ..., An>`  | `Metafunction`
     */
    struct Logical {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename L>
        struct not_impl;
#endif

        /*!
         * Returns `A::type` if `not_<A>::value` is `true` and
         * `B::type` otherwise.
         */
        template <typename A, typename B>
        struct and_impl;

        /*!
         * Returns `B::type` if `not_<A>::value` is `true` and
         * `A::type` otherwise.
         */
        template <typename A, typename B>
        struct or_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LOGICAL_HPP
