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
#include <boost/mpl11/foldl.hpp>
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


namespace boost { namespace mpl11 {
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


    template <typename Locals, typename F>
    struct let_expression;

    //////////////////////////
    // if_chain
    //////////////////////////
    template <typename Cond, typename Then, typename Else>
    struct if_chain
        : detail::conditional<Cond::value, Then, Else>::type
    { };

    //////////////////////////
    // lazy_let_expression
    //////////////////////////
    template <typename Locals, typename Expression>
    struct lazy_let_expression
        : let_expression<Locals, typename Expression::type>
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
    struct let_expression_impl;

    template <typename Locals, template <typename ...> class F, typename ...T>
    struct evaluate_recursively;

    template <typename F, typename Locals, typename ...Args>
    struct closure;

    template <typename Locals, typename F>
    struct let_expression
        : if_chain<is_placeholder<F>,
            F,

          /* else */ if_chain<has_key<Locals, F>,
            lazy_let_expression<Locals, at_key<Locals, F>>,

          /* else */
            let_expression_impl<Locals, F>
        >>
    { };

    template <typename Outer, typename ...Inner, typename Expression>
    struct let_expression<Outer, let<Inner...>(*)(Expression)>
        : let_expression<
            Outer, typename let<Inner...>::template in<Expression>
        >
    { };

    template <typename Outer, typename ...Inner, typename Expression>
    struct let_expression<Outer, let<Inner...>(Expression)>
        : let_expression<
            Outer, typename let<Inner...>::template in<Expression>
        >
    { };

    template <typename _, typename F, typename Locals, typename ...Args>
    struct let_expression<_, closure<F, Locals, Args...>> {
        template <typename ...>
        using apply = mpl11::apply<let_expression<Locals, F>, Args...>;
    };

    template <typename Outer, typename Inner, typename T>
    struct let_expression<Outer, let_expression<Inner, T>> {
        template <typename ...Args>
        using apply = identity<
            let_expression<
                insert_keys_t<
                    typename close_over<Outer, Args...>::type,
                    Inner
                >,
                T
            >
        >;
    };

    template <typename Locals, typename F>
    struct let_expression_impl {
        template <typename ...Args>
        using apply = identity<F>;
    };

    template <typename Locals, template <typename ...> class F, typename ...T>
    struct let_expression_impl<Locals, F<T...>>
        : detail::conditional<is_local_expr<Locals, T...>::value,
            evaluate_recursively<Locals, F, T...>,
            always<F<T...>>
        >::type
    { };

    template <typename Locals, template <typename ...> class F, typename ...T>
    struct fast_eval {
        template <typename ...Args>
        using apply = F<apply_t<let_expression<Locals, T>, Args...>...>;
    };

    template <typename Locals, template <typename ...> class F, typename ...T>
    struct slow_eval {
        template <typename ...Args>
        struct gather {
            template <typename State, typename P>
            using apply = typename detail::conditional<
                is_variadic_placeholder<P>::value,
                join<State, apply_t<let_expression<Locals, P>, Args...>>,
                push_back<State, apply_t<let_expression<Locals, P>, Args...>>
            >::type;
        };

        template <typename ...Args>
        using apply = unpack<
            foldl_t<vector<T...>, vector<>, gather<Args...>>, quote<F>
        >;
    };

    template <typename Locals, template <typename ...> class F, typename ...T>
    struct evaluate_recursively
        : detail::conditional<
            or_c<is_variadic_placeholder<T>::value..., false, false>::value,
            slow_eval<Locals, F, T...>,
            fast_eval<Locals, F, T...>
        >::type
    { };
} // end namespace let_detail

template <typename ...Locals, typename Expression, typename ...Args>
struct apply<let<Locals...>(Expression), Args...>
    : apply<typename let<Locals...>::template in<Expression>, Args...>
{ };

template <typename ...Locals, typename Expression, typename ...Args>
struct apply<let<Locals...>(*)(Expression), Args...>
    : apply<typename let<Locals...>::template in<Expression>, Args...>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LET_HPP
