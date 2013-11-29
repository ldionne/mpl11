/*!
 * @file
 * Forward declares `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_FWD_APPLY_HPP
#define BOOST_MPL11_FWD_APPLY_HPP

namespace boost { namespace mpl11 {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup concepts
     *
     * Compile-time invokable entity that is first-class in the C++
     * template system.
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `F`        | A `MetafunctionClass`
     * | `Args...`  | An arbitrary sequence of types
     *
     *
     * ## Valid expressions
     * | Expression                | Type
     * | ----------                | ----
     * | `apply<F, Args...>::type` | Any type
     *
     *
     * @note
     * This concept only lives in the documentation. There exists no such
     * `struct` in the library.
     */
    struct MetafunctionClass { };
#endif

    /*!
     * @ingroup metafunctions
     *
     * Invokes a `MetafunctionClass` `F` with arguments `Args...`.
     *
     * If `Args...` are provided, `apply` is just a wrapper over
     * `F::apply<Args...>`. Otherwise, `apply` is either `F::apply`
     * or `F::apply<>`, depending on which expression is valid.
     *
     *
     * @note
     * If `F::apply<Args...>` (or `F::apply`) is an invalid expression, an
     * incomplete type or a type from which one can't derive, a hard error
     * is triggered.
     */
    template <typename F, typename ...Args>
    struct apply;

    template <typename F, typename ...Args>
    using apply_t = typename apply<F, Args...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_APPLY_HPP
