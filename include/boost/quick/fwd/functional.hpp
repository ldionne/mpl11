/*!
 * @file
 * Forward declares the @ref Functional module.
 */

#ifndef BOOST_MPL11_FWD_FUNCTIONAL_HPP
#define BOOST_MPL11_FWD_FUNCTIONAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @defgroup Functional Functional
     *
     * General purpose metafunctions and metafunction classes.
     *
     * @{
     */

    /*!
     * Returns a constant metafunction class returning `x` regardless of
     * the arguments it is invoked with.
     */
    template <typename x>
    struct always;

    /*!
     * Returns a metafunction class invoking `f` with its two first arguments
     * in reverse order.
     *
     * Specifically, `apply<flip<f>, a0, a1, a2, ..., aN>` is
     * equivalent to `apply<f, a1, a0, a2, ..., aN>`.
     */
    template <typename f>
    struct flip;

    /*!
     * Returns the composition of several metafunction classes.
     *
     * Let `f(x)` denote `apply<f, x>` to lighten the notation. Then,
     * `apply<compose<f1, f2, ..., fN>, a1, ..., aN>` is equivalent to
     * `f1(f2(...fN(a1, ..., aN)...))`, and `compose<f>` is equivalent to `f`.
     */
    template <typename f, typename ...fs>
    struct compose;

    /*!
     * Invokes a metafunction class with the given arguments.
     *
     * This is effectively just a wrapper over `f::type::apply<x...>`.
     */
    template <typename f, typename ...x>
    struct apply;

    //! The identity metafunction - returns its argument unchanged.
    template <typename x>
    using id = x;

    /*!
     * Turns a metafunction into an equivalent metafunction class.
     *
     * Specifically, `apply<quote<f>, x...>` is equivalent to `f<x...>`.
     */
    template <template <typename ...> class f>
    struct quote;

    /*!
     * Returns a specialization of the given template with the
     * provided arguments.
     *
     * Specifically, `apply<into<tp>, x...>::%type` is the same as `tp<x...>`.
     */
    template <template <typename ...> class tp>
    struct into;

    /*!
     * Returns a partially applied metafunction class.
     *
     * Specifically, `apply<partial<f, x...>, args...>` is equivalent to
     * `apply<f, x..., args...>`.
     *
     *
     * @note
     * `partial` is specialized for `quote` and `into` so that patterns like
     * `partial<quote<equal>, x...>` are as efficient as writing a custom
     * metafunction class.
     */
    template <typename f, typename ...x>
    struct partial;

    /*!
     * Returns a metafunction class computing the least fixed point of `f`.
     *
     * `fix` is an implementation of the Y-combinator, also called the fixed
     * point combinator. It encodes the idea of recursion, and in fact any
     * recursive metafunction can be written in terms of it.
     *
     * Specifically, `f` must be a metafunction class whose first argument
     * is another metafunction class. Then, `apply<fix<f>, args...>` is
     * equivalent to `apply<f, partial<f, fix<f>>, args...>`.
     */
    template <typename f>
    struct fix;

    /*!
     * Like `compose`, except that multiple arguments are passed to the
     * leftmost metafunction.
     *
     * Let `f(x)` denote `apply<f, x>` to lighten the notation. Then,
     * `on<f, fs...>(x...)` is equivalent to `f(compose<fs...>(x)...)`.
     *
     * @todo Find a better name for this.
     */
    template <typename f, typename ...fs>
    struct on;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FUNCTIONAL_HPP
