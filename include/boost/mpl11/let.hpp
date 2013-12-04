/*!
 * @file
 * Defines `boost::mpl11::let`.
 */

#ifndef BOOST_MPL11_LET_HPP
#define BOOST_MPL11_LET_HPP

#include <boost/mpl11/fwd/let.hpp>

#include <boost/mpl11/imap.hpp> // required by fwd/let.hpp
#include <boost/mpl11/pair.hpp> //

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/detail/tp_conditional.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/insert_keys.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/transform.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/value_of.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
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

    template <typename Cond, typename Then, typename Else>
    struct if_chain
        : detail::conditional<Cond::value, Then, Else>::type
    { };

    template <typename Context, typename F, typename ...T>
    class bind {
        template <typename ...Args>
        using fast_apply = mpl11::apply<
            F, apply_t<let_expr<Context, T>, Args...>...
        >;

        template <typename ...Args>
        struct gather {
            template <typename State, typename U>
            using apply = typename detail::tp_conditional<
                is_multivalued_placeholder<U>::value,
                join,
                push_back
            >::template type<State, apply_t<let_expr<Context, U>, Args...>>;
        };

        template <typename ...Args>
        using slow_apply = unpack<
            foldl_t<vector<T...>, vector<>, gather<Args...>>, F
        >;

    public:
        template <typename ...Args>
        using apply = typename detail::tp_conditional<
            or_c<is_multivalued_placeholder<T>::value..., false, false>::value,
            slow_apply,
            fast_apply
        >::template type<Args...>;
    };

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

    template <typename Outer, typename ...Inner, typename Expression>
    struct let_expr<Outer, let<Inner...>(*)(Expression)>
        : let_expr<Outer, typename let<Inner...>::template in<Expression>>
    { };

    template <typename Outer, typename ...Inner, typename Expression>
    struct let_expr<Outer, let<Inner...>(Expression)>
        : let_expr<Outer, typename let<Inner...>::template in<Expression>>
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LET_HPP
