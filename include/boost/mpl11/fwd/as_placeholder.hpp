/*!
 * @file
 * Forward declares `boost::mpl11::as_placeholder`.
 */

#ifndef BOOST_MPL11_FWD_AS_PLACEHOLDER_HPP
#define BOOST_MPL11_FWD_AS_PLACEHOLDER_HPP

namespace boost { namespace mpl11 {
    /*!
     * Customization point to create new `Placeholder`s.
     *
     * See `Placeholder` for the exact semantics of `as_placeholder`.
     */
    template <typename T>
    struct as_placeholder;

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @defgroup placeholders Placeholders
     *
     * General purpose `Placeholder`s predefined by the library.
     */

    /*!
     * @ingroup concepts
     *
     * Type with special semantics when used inside `LetExpression`s.
     *
     * Specifically, a `Placeholder` is a type using `as_placeholder` as a
     * customization point to customize its behavior inside `LetExpression`s.
     *
     * The library predefines some `Placeholder`s that are of general
     * interest. By convention, their name always start with a single
     * underscore (`_`) to make them stand out.
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `P`        | A `Placeholder`
     * | `Args...`  | An arbitrary sequence of types
     * | `Context`  | An `AssociativeSequence`
     *
     *
     * ## Valid expressions
     * | Expression                                                 | Type                       | Semantics
     * | ----------                                                 | ----                       | ---------
     * | `as_placeholder<P>::is_multivalued<Context, Args...>`      | Boolean `IntegralConstant` | Whether the result of applying `P` in the provided context yields several results, which should be expanded into the containing expression.
     * | `as_placeholder<P>::triggers_evaluation<Context, Args...>` | Boolean `IntegralConstant` | Whether the appearance of `P` inside an expression in the provided context should trigger the evaluation of the expression (as a `Metafunction`) after performing placeholder substitution.
     * | `as_placeholder<P>::apply<Context, Args...>::type`         | Any type                   | The result of applying `P` in the provided context. If `P` is multivalued, this must be a `Sequence`.
     *
     *
     * @note
     * This concept only lives in the documentation. There exists no such
     * `struct` in the library.
     */
    struct Placeholder { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AS_PLACEHOLDER_HPP
