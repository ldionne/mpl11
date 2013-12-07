/*!
 * @file
 * Defines `boost::mpl11::detail::eval_placeholder_expr`.
 */

#ifndef BOOST_MPL11_DETAIL_EVAL_PLACEHOLDER_EXPR_HPP
#define BOOST_MPL11_DETAIL_EVAL_PLACEHOLDER_EXPR_HPP

namespace boost { namespace mpl11 { namespace detail {
    struct join_variadics_and_push_back_the_rest {
        template <typename State, typename X>
        struct apply;

        template <typename State, typename T>
        struct apply<State, pair<true_, T>>
            : join<State, T>
        { };

        template <typename State, typename T>
        struct apply<State, pair<false_, T>>
            : push_back<State, T>
        { };
    };

    template <template <typename> class Apply>
    struct contextual_bind {
    private:
        template <typename F, typename ...>
        struct apply_impl;

        // At least one of the Ts is a variadic placeholder.
        template <typename F, typename ...IsVariadicPlaceholder, typename ...T>
        struct apply_impl<F, pair<IsVariadicPlaceholder, T>...>
            : unpack<
                foldl_t<
                    vector<pair<IsVariadicPlaceholder, Apply<T>>...>,
                    vector<>,
                    join_variadics_and_push_back_the_rest
                >,
                F
            >
        { };

        // None of the Ts is a variadic placeholder.
        template <typename F, typename ...T>
        struct apply_impl<F, pair<false_, T>...>
            : mpl11::apply<F, Apply<T>...>
        { };

    public:
        template <typename F, typename ...T>
        struct apply
            : apply_impl<
                F, pair<bool_<is_variadic_placeholder<T>::value>, T>...
            >
        { };
    };



    /*!
     * @ingroup details
     *
     * Evaluates a `PlaceholderExpression` within a given context.
     *
     * This effectively implements the algorithm documented in the
     * `PlaceholderExpression` concept.
     */
    template <typename Context, typename Expression>
    struct eval_placeholder_expr
        : detail::conditional<is_placeholder<Expression>::value,
            apply<as_placeholder<Expression>, Context>,
            identity<Expression>
        >::type
    { };

    template <typename Context, template <typename ...> class F, typename ...T>
    struct eval_placeholder_expr<Context, F<T...>>
        : if_chain<is_placeholder<F<T...>>,
            apply<as_placeholder<F<T...>>, Context>,

          /* else */ if_chain<is_placeholder_expr<F<T...>>,
            context_bind<Context, quote<F>, T...>,

          /* else */
            identity<F<T...>>
        >>
    { };

    template <typename Inner, typename Expression>
    struct as_placeholder<let_expr<Inner, Expression>> {
        template <typename Outer>
        struct apply {
            template <typename Pair>
            struct bind_args {
                using type = pair<
                    key_of_t<Outer, Pair>,
                    // We should allow them to refer to other bindings in
                    // Inner too.
                    eval_placeholder_expr<
                        Outer, value_of_t<Outer, Pair>
                    >
                >;
            };

            using type = let_expr<
                insert_keys_t<
                    transform_t<Outer, quote<bind_args>>,
                    Inner
                >,
                Expression
            >;
        };
    };


    template <typename Context>
    struct bound_let {

    };

    template <typename Bindings>
    struct unbound_let {
        template <typename Context>
        struct apply {
            using type = bound_let<
                // Overwrite the context with our bindings and
                ...
            >;
        };
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_EVAL_PLACEHOLDER_EXPR_HPP
