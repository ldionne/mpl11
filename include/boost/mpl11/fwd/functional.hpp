/*!
 * @file
 * Forward declares the @ref Functional module.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_FUNCTIONAL_HPP
#define BOOST_MPL11_FWD_FUNCTIONAL_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup Functional Functional
     *
     * General purpose metafunctions and metafunction classes.
     *
     *
     * @note
     * For legibility reasons, `apply<f, x1, ..., xn>` is sometimes noted as
     * `f(x1, ..., xn)` in the documentation.
     *
     *
     * @todo
     * - Consider moving `into` out of this module. Maybe it would fit better
     *   with other utilities manipulating template specializations.
     * - Try generalizing `rsect` and `lsect`. Not sure it can be done, but
     *   here's some brain food:
        @code
            rsectn<0, f, x1, ..., xn>::apply<> == f<x1, ..., xn>
            rsectn<1, f, x2, ..., xn>::apply<x1> == f<x1, x2, ..., xn>
            rsectn<2, f, x3, ..., xn>::apply<x1, x2> == f<x1, x2, x3, ..., xn>
        @endcode
     *
     * It also seems like there may be some kind of operation modifying
     * how functions are applied:
     *
        @code
            f x1 ... xn                 // shiftr 0
            x1 f x2 ... xn              // shiftr 1
            x1 x2 f x3 ... xn           // shiftr 2
            x1 x2 x3 f x4 ... xn        // shiftr 3

            x1 x2 x3 f x4 ... xn        // shiftl 0
            x1 x2 f x3 ... xn           // shiftl 1
            x1 f x2 ... xn              // shiftl 2
            f x1 ... xn                 // shiftl 3
        @endcode
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
     * Invokes a metafunction class with the given arguments.
     *
     * This is effectively just a wrapper over `f::type::apply<x...>`.
     */
    template <typename f, typename ...x>
    struct apply;

    /*!
     * Invokes a curried metafunction class with the given arguments.
     *
     * Specifically, `apply_curried<f, x1, ..., xn>` is equivalent to
     * `f(x1)...(xn)`.
     */
    template <typename f, typename ...x>
    struct apply_curried;

    //! The identity metafunction - returns its argument unchanged.
    template <typename x>
    BOOST_MPL11_DOXYGEN_ALIAS(id, x);

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
     * Returns a curried metafunction class.
     *
     * `n` must be a positive (meaning `!= 0`) integer representing the
     * number of curried arguments of the created metafunction class.
     * Specifically, `curry<n, f>(x1)...(xn)` is equivalent to
     * `f(x1, ..., xn)`.
     */
    template <detail::std_size_t n, typename f>
    struct curry;

    /*!
     * Returns a uncurried metafunction class.
     *
     * `n` must be a positive (meaning `!= 0`) integer representing the
     * number of arguments taken by `f` in curried form. Specifically,
     * `uncurry<n, f>(x1, ..., xn)` is equivalent to `f(x1)...(xn)`.
     */
    template <detail::std_size_t n, typename f>
    struct uncurry;

    /*!
     * Returns a metafunction class computing the least fixed point of `f`.
     *
     * `fix` is an implementation of the Y-combinator, also called the fixed
     * point combinator. It encodes the idea of recursion, and in fact any
     * recursive metafunction can be written in terms of it.
     *
     * `f` must be a metafunction class whose first argument is another
     * metafunction class. Then, `apply<fix<f>, args...>` is equivalent
     * to `apply<f, partial<f, fix<f>>, args...>`.
     */
    template <typename f>
    struct fix;

    /*!
     * Returns the composition of several metafunction classes.
     *
     * Specifically, `apply<compose<f, g>, x, xs...>` is equivalent to
     * `apply<f, apply<g, x>, xs...>`, and `compose<f>` is equivalent to `f`.
     * Note that only the first argument is passed to `g`; use `bind<f, g>`
     * instead if all the arguments must be passed to `g`.
     *
     * More than two metafunction classes can also be composed at once;
     * `compose<f1, f2, fs...>` is equivalent to
     * `compose<f1, compose<f2, fs...>>`. Also note that `compose` is
     * associative, i.e. `compose<f, compose<g, h>>` is equivalent to
     * `compose<compose<f, g>, h>`.
     *
     *
     * @internal
     * Haskell pseudo-code:
        @code
            -- definition (`.` is `compose`)
            f . g $ x xs... = f (g x) xs...

            -- proof of associativity
            f . (g . h) $ x xs... == f ((g . h) x) xs...
                                  == f (g (h x)) xs...

            (f . g) . h $ x xs... == (f . g) (h x) xs...
                                  == f (g (h x)) xs...
        @endcode
     *
     */
    template <typename f, typename ...fs>
    struct compose;

    /*!
     * Invokes `f` with the result of mapping `g` on each argument.
     *
     * Specifically, `apply<argmap<f, g>, x...>` is equivalent to
     * `apply<f, apply<g, x>...>`.
     *
     *
     * @note
     * `argmap` is associative, i.e. `argmap<f, argmap<g, h>>` is equivalent
     * to `argmap<argmap<f, g>, h>`.
     *
     *
     * @internal
     * Haskell pseudo-code:
        @code
            -- definition
            argmap f g $ xs... = f (g xs)...

            -- proof of associativity
            argmap f (argmap g h) $ xs... == f ((argmap g h) xs)...
                                          == f (g (h xs))...

            argmap (argmap f g) h $ xs... == (argmap f g) (h xs)...
                                          == f (g (h xs))...
        @endcode
     *
     */
    template <typename f, typename g>
    struct argmap;

    /*!
     * Invokes `f` with the result of invoking `fs...` on each corresponding
     * argument.
     *
     * Specifically, `apply<on<f, fs...>, x...>` is equivalent to
     * `apply<f, apply<fs, x>...>`. The `fs...` are applied to the
     * arguments in lockstep. Hence, the arity of `on` is determined
     * by the number of `fs...`.
     *
     *
     * @internal
     * Haskell pseudo-code:
        @code
            -- definition
            on f fs... $ xs... == f (fs xs)...
        @endcode
     *
     */
    template <typename f, typename ...fs>
    struct on;

    /*!
     * Invokes `f` with the result of invoking each `fs...` with the
     * arguments.
     *
     * Specifically, `apply<bind<f, fs...>, x...>` is equivalent to
     * `apply<f, apply<fs, x...>...>`. The arity of `f` must match the
     * number of `fs...`.
     *
     *
     * @note
     * When used with two metafunction classes only, `bind` has the property
     * of being associative, i.e. `bind<f, bind<g, h>>` is equivalent to
     * `bind<bind<f, g>, h>`.
     *
     *
     * @internal
     * Haskell pseudo-code:
        @code
            -- definition
            bind f fs... $ xs... == f (fs xs...)...

            -- proof of associativity (in the binary case)
            bind f (bind g h) $ xs... == f ((bind g h) xs...)
                                      == f (g (h xs...))

            bind (bind f g) h $ xs... == (bind f g) (h xs...)
                                      == f (g (h xs...))
        @endcode
     *
     */
    template <typename f, typename ...fs>
    struct bind;

    /*!
     * Returns the `n`th of its arguments.
     *
     * Indexing starts at 1, so that `arg<1>` returns the 1st argument,
     * `arg<2>` the 2nd and so on. Using `arg<0>` is an error. Passing
     * less than `n` arguments to `arg<n>` is also an error.
     */
    template <detail::std_size_t n>
    struct arg;

    /*!
     * Applies a metafunction class in infix notation.
     *
     * Specifically, `infix<x, f, y>` is equivalent to `apply<f, x, y>`.
     * Using `infix` improves legibility when applying some metafunction
     * classes such as `on`. Consider `infix_<f, on, g>` versus `on<f, g>`.
     * The former reads naturally while the latter requires knowing what
     * each argument stands for.
     */
    template <typename x, typename f, typename y>
    BOOST_MPL11_DOXYGEN_ALIAS(infix, apply<f, x, y>);

    //! Equivalent to `infix<x, quote<f>, y>`; provided for convenience.
    template <typename x, template <typename ...> class f, typename y>
    BOOST_MPL11_DOXYGEN_ALIAS(infix_, f<x, y>);

    /*!
     * Returns the left section of `f` with `x`.
     *
     * Specifically, `lsect<x, f>(y)` is equivalent to `f(x, y)`. This is
     * mainly useful to increase legibility when partially applying
     * metafunction classes that are logically infix operators.
     */
    template <typename x, typename f>
    BOOST_MPL11_DOXYGEN_ALIAS(lsect, partial<f, x>);

    //! Equivalent to `lsect<x, quote<f>>`; provided for convenience.
    template <typename x, template <typename ...> class f>
    BOOST_MPL11_DOXYGEN_ALIAS(lsect_, lsect<x, quote<f>>);

    /*!
     * Returns the right section of `f` with `y`.
     *
     * Specifically, `rsect<f, y>(x)` is equivalent to `f(x, y)`. This is
     * mainly useful to increase legibility when partially applying
     * metafunction classes that are logically infix operators.
     */
    template <typename f, typename y>
    BOOST_MPL11_DOXYGEN_ALIAS(rsect, partial<flip<f>, y>);

    //! Equivalent to `rsect<quote<f>, y>`; provided for convenience.
    template <template <typename ...> class f, typename y>
    BOOST_MPL11_DOXYGEN_ALIAS(rsect_, rsect<quote<f>, y>);

    /*!
     * Convenience namespace containing everything provided by the
     * @ref Functional module.
     */
    namespace functional {
        using mpl11::always;
        using mpl11::apply;
        using mpl11::apply_curried;
        using mpl11::arg;
        using mpl11::argmap;
        using mpl11::bind;
        using mpl11::compose;
        using mpl11::curry;
        using mpl11::fix;
        using mpl11::flip;
        using mpl11::id;
        using mpl11::infix;
        using mpl11::infix_;
        using mpl11::into;
        using mpl11::lsect;
        using mpl11::lsect_;
        using mpl11::on;
        using mpl11::partial;
        using mpl11::quote;
        using mpl11::rsect;
        using mpl11::rsect_;
        using mpl11::uncurry;
    }
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FUNCTIONAL_HPP
