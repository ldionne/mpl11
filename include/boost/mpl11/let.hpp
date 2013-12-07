/*!
 * @file
 * Defines `boost::mpl11::let`.
 */

#ifndef BOOST_MPL11_LET_HPP
#define BOOST_MPL11_LET_HPP

#include <boost/mpl11/fwd/let.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/at_key.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/fwd/pair.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/imap.hpp>
#include <boost/mpl11/insert_key.hpp>
#include <boost/mpl11/insert_keys.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/vector.hpp>
#include <boost/mpl11/flip.hpp>


namespace boost { namespace mpl11 {
namespace let_detail {
    //! @todo Replace this by `if_` once it supports multiple branches.
    template <typename Cond, typename Then, typename Else>
    struct if_chain
        : detail::conditional<Cond::value, Then, Else>::type
    { };

    template <typename Outer, typename ...Inner, typename Expression>
    struct let_expr<Outer, let<Inner...>(*)(Expression)>
        : let_expr<Outer, typename let<Inner...>::template in<Expression>>
    { };

    template <typename Outer, typename ...Inner, typename Expression>
    struct let_expr<Outer, let<Inner...>(Expression)>
        : let_expr<Outer, typename let<Inner...>::template in<Expression>>
    { };

    template <typename Bindings, typename F, typename ...>
    struct bind_impl;

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

    // At least one of the Ts is a variadic placeholder.
    template <
        typename Bindings, typename F,
        typename ...IsVariadicPlaceholder, typename ...T
    >
    struct bind_impl<Bindings, F, pair<IsVariadicPlaceholder, T>...> {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply, unpack<
            foldl_t<
                vector<
                    pair<
                        IsVariadicPlaceholder,
                        apply_t<let_expr<Bindings, T>, Args...>
                    >...
                >,
                vector<>,
                join_variadics_and_push_back_the_rest
            >,
            F
        >);
    };

    // None of the Ts is a variadic placeholder.
    template <typename Bindings, typename F, typename ...T>
    struct bind_impl<Bindings, F, pair<false_, T>...> {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply, mpl11::apply<
            F, apply_t<let_expr<Bindings, T>, Args...>...
        >);
    };

    template <typename Bindings, typename F, typename ...T>
    struct bind
        : bind_impl<
            Bindings,
            F,
            pair<bool_<is_variadic_placeholder<T>::value>, T>...
        >
    { };
} // end namespace let_detail

template <typename ...Bindings, typename Expression, typename ...Args>
struct apply<let<Bindings...>(Expression), Args...>
    : apply<typename let<Bindings...>::template in<Expression>, Args...>
{ };

template <typename ...Bindings, typename Expression, typename ...Args>
struct apply<let<Bindings...>(*)(Expression), Args...>
    : apply<typename let<Bindings...>::template in<Expression>, Args...>
{ };


#if 0
namespace let_detail {
    template <typename T>
    struct is_placeholder_expr
        : is_placeholder<T>
    { };

    template <template <typename ...> class F, typename ...T>
    struct is_placeholder_expr<F<T...>>
        : or_c<
            is_placeholder<F<T...>>::value,
            is_placeholder_expr<T>::value...,
            false
        >
    { };

    template <typename Context, typename Expression>
    struct let_expr
        : detail::conditional<is_placeholder<Expression>::value,
            partial<Expression, Context>,
            always<Expression>
        >::type
    { };

    template <typename Outer, typename Inner, typename Expression>
    struct let_expr<Outer, let_expr<Inner, Expression>> {
        template <typename ...Args>
        class apply {
            template <typename Pair>
            struct bind_args {
                using type = pair<
                    key_of_t<Outer, Pair>,
                    mpl11::apply<value_of_t<Outer, Pair>, Args...>
                >;
            };

        public:
            using type = let_expr<
                insert_keys_t<
                    transform_t<Outer, quote<bind_args>>,
                    Inner
                >,
                Expression
            >;
        };
    };

    template <typename Context, template <typename ...> class F, typename ...T>
    struct let_expr<Context, F<T...>>
        : if_chain<is_placeholder<F<T...>>,
            partial<F<T...>, Context>,

        /* else */ if_chain<is_placeholder_expr<F<T...>>,
            bind<quote<F>, T...>,

        /* else */
            always<F<T...>>
        >>
    { };
} // end namespace let_detail
#endif
namespace let_detail {
    //////////////////////////
    // close_over
    //////////////////////////
    template <typename F, typename Locals, typename ...Args>
    struct closure;

    template <typename Locals, typename ...Args>
    struct insert_closure {
        template <typename Map, typename Local>
        struct apply;

        template <typename Map, typename K, typename V>
        struct apply<Map, local<K, V>>
            : insert_key<Map, local<K, closure<V, Locals, Args...>>>
        { };
    };

    template <typename Locals, typename ...Args>
    struct close_over
        : foldl<Locals, imap<>, insert_closure<Locals, Args...>>
    { };

    //////////////////////////
    // lazy_let_expression
    //////////////////////////
    template <typename Locals, typename Expression>
    struct lazy_let_expr
        : let_expr<Locals, typename Expression::type>
    { };

    //////////////////////////
    // is_local_expr
    //////////////////////////
    template <typename Locals, typename ...T>
    struct is_local
        : or_c<is_local<Locals, T>::value..., false, false>
    { };

    template <typename Locals, typename T>
    struct is_local<Locals, T>
        : bool_<(is_placeholder<T>::value || has_key<Locals, T>::value)>
    { };

    template <typename Locals, typename ...T>
    struct is_local_expr
        : or_<is_local_expr<Locals, T>..., false_, false_>
    { };

    template <typename Locals, typename T>
    struct is_local_expr<Locals, T>
        : is_local<Locals, T>
    { };

    template <typename Locals, template <typename ...> class F, typename ...T>
    struct is_local_expr<Locals, F<T...>>
        : or_<
            is_local<Locals, F<T...>, T...>,
            // We got some overlap here, but it should not be too wasteful.
            // is_local will be checked twice for T..., but that does not
            // cause more instantiations.
            is_local_expr<Locals, T>...,
            false_
        >
    { };


    //////////////////////////
    // let_expression
    //////////////////////////
    template <typename Locals, typename F>
    struct let_expr_impl;

    template <typename F, typename Locals, typename ...Args>
    struct closure;

    template <typename Locals, typename F>
    struct let_expr
        : if_chain<is_placeholder<F>,
            F,

          /* else */ if_chain<has_key<Locals, F>,
            lazy_let_expr<Locals, at_key<Locals, F>>,

          /* else */
            let_expr_impl<Locals, F>
        >>
    { };

    template <typename _, typename F, typename Locals, typename ...Args>
    struct let_expr<_, closure<F, Locals, Args...>> {
        template <typename ...>
        BOOST_MPL11_NESTED_ALIAS(apply,
            mpl11::apply<let_expr<Locals, F>, Args...>);
    };

    template <typename Outer, typename Inner, typename T>
    struct let_expr<Outer, let_expr<Inner, T>> {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply, identity<
            let_expr<
                insert_keys_t<
                    typename close_over<Outer, Args...>::type,
                    Inner
                >,
                T
            >
        >);
    };

    template <typename Locals, typename F>
    struct let_expr_impl {
        template <typename ...Args>
        using apply = identity<F>;
    };

    template <typename Locals, template <typename ...> class F, typename ...T>
    struct let_expr_impl<Locals, F<T...>>
        : detail::conditional<is_local_expr<Locals, T...>::value,
            bind<Locals, quote<F>, T...>,
            always<F<T...>>
        >::type
    { };
} // end namespace let_detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LET_HPP
