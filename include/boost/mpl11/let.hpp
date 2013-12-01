/*!
 * @file
 * Defines `boost::mpl11::let`.
 */

#ifndef BOOST_MPL11_LET_HPP
#define BOOST_MPL11_LET_HPP

#include <boost/mpl11/fwd/let.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/as_placeholder.hpp>
#include <boost/mpl11/at_key.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/detail/tp_conditional.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/imap.hpp>
#include <boost/mpl11/insert_key.hpp>
#include <boost/mpl11/insert_keys.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
    template <typename Context, typename F, typename ...T>
    class bind {
        template <typename ...Args>
        using fast_apply = mpl11::apply<
            F, apply_t<let_expr<Context, T>, Args...>...
        >;

        template <typename ...Args>
        struct gather {
            template <typename State, typename T>
            using apply = typename detail::tp_conditional<
                as_placeholder<T>::template is_multivalued<Context, Args...>::value,
                join,
                push_back
            >::template type<State, apply_t<let_expr<Context, T>, Args...>>;
        };

        template <typename ...Args>
        using slow_apply = unpack<
            foldl_t<vector<T...>, vector<>, gather<Args...>>, F
        >;

    public:
        template <typename ...Args>
        using apply = typename detail::tp_conditional<
            or_c<as_placeholder<T>::template is_multivalued<Context, Args...>::value..., false, false>::value,
            slow_apply,
            fast_apply
        >::template type<Args...>;
    };

    template <typename Context, typename F>
    struct let_expr
        : detail::conditional<is_placeholder<F>::value,
            partial<F, Context>,
            always<F>
        >::type
    { };

    template <typename Context, template <typename ...> class F, typename ...T>
    struct let_expr<Context, F<T...>>
        : if_chain<is_placeholder<F<T...>>,
            partial<F<T...>, Context>,

          /* else */ if_chain<requires_evaluation<F<T...>>,
                bind<Context, quote<F>, T...>,

          /* else */
                bind<Context, into<F>, T...>
        >>
    { };


    struct context_class final : detail::associative_sequence_adaptor {
        template <typename Context, typename Name, typename Default>
        struct at_key_def_impl;

        template <typename Outer, typename Inner, typename Name, typename Default>
        struct at_key_def_impl<context<Outer, Inner>, Name, Default>
            : detail::conditional<has_key<Inner, Name>::value,
                let_expr<??, at_key_t<Inner, Name>>,
                at_key_t<Outer, Name, Default>
            >
        { };
    };


    template <typename Outer, typename Inner, typename F>
    struct let_expr<Outer, let_expr<Inner, F>> {
        template <typename ...Args>
        struct apply {
            using Context = insert_key_t<
                insert_keys_t<Outer, Inner>,
                pair<detail::all_args, vector<Args...>>
            >;
            using NewInner = transform_values<
                Inner,
                in_context<Context, _1>
            >;

            using type = let_expr<
                NewInner, F
            >;
        };
    };
}} // end namespace boost::mpl11













namespace boost { namespace mpl11 {
namespace detail {
    template <typename Context, typename F>
    struct lambda {
        template <typename ...Args>
        struct apply
            : as_placeholder<F>::template apply<Context, Args...> ???
        { };
        should as_placeholder be lambda instead??
    };
} // end namespace detail

template <typename F>
using lambda = detail::lambda<imap<>, F>;



namespace let_detail {
    template <typename T>
    struct requires_evaluation;

    template <typename Context, typename F>
    struct closure {
        template <typename ...Args>
        struct apply;
    };

    template <typename Context, template <typename ...> class F, typename ...T>
    struct closure<Context, F<T...>> {
        template <typename ...Args>
        struct apply
            : if_<is_placeholder<F<T...>>,
                ...,
                bind<
                    typename detail::conditional<
                        requires_evaluation<F<T...>>::value,
                        quote<F>,
                        into<F>
                    >::type,
                    T...
                >
    };

    template <typename Outer, typename Inner, typename F>
    struct closure<Outer, closure<Inner, F>> {
        template <typename ...Args>
        struct apply;
    };




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
} // end namespace let_detail

template <typename ...Context, typename Expression, typename ...Args>
struct apply<let<Context...>(Expression), Args...>
    : apply<typename let<Context...>::template in<Expression>, Args...>
{ };

template <typename ...Context, typename Expression, typename ...Args>
struct apply<let<Context...>(*)(Expression), Args...>
    : apply<typename let<Context...>::template in<Expression>, Args...>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LET_HPP






/*!
 * @file
 * Defines `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_LAMBDA_HPP
#define BOOST_MPL11_LAMBDA_HPP

#include <boost/mpl11/fwd/lambda.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/tp_conditional.hpp>
#include <boost/mpl11/detail/vector_concat.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
namespace lambda_detail {
    template <
        typename Context,
        bool TriggersRecursiveEval, bool IsMultiValued,
        template <typename ...> class F, typename ...T>
    struct lambda_impl;

    template <
        typename Context, bool IsMultiValued,
        template <typename ...> class F, typename ...T>
    struct lambda_impl<Context, true, IsMultiValued, F, T...> {
        template <typename ...Args>
        using apply = typename lambda_impl<Context, false, IsMultiValued, F, T...>::template apply<Args...>::type;
    };

    template <typename Context, template <typename ...> class F, typename ...T>
    struct lambda_impl<Context, false, false, F, T...> {
        template <typename ...Args>
        using apply = identity<F<apply_t<lambda<Context, T>, Args...>...>>;
    };

    template <typename Context, template <typename ...> class F, typename ...T>
    struct lambda_impl<Context, false, true, F, T...> {
        template <typename ...Args>
        using apply = unpack<
            foldl_t<vector<T...>, vector<>, gather<Context, Args...>>,
            into<F>
        >;
    };

    template <typename Context, typename T>
    struct lambda {
        template <typename ...>
        using apply = identity<T>;
    };

    template <typename Context, typename T>
    struct lambda<Context, lambda<T>> {
        template <typename ...>
        using apply = identity<lambda<T>>;
    };

    //! @todo Remove trailing `false`s once we're fixed on the arity of `or_`.
    template <typename Context, template <typename ...> class F, typename ...T>
    struct lambda<Context, F<T...>>
        : lambda_impl<
            or_c<as_placeholder<T>::triggers_evaluation..., false, false>::value,
            or_c<as_placeholder<T>::is_multivalued..., false, false>::value,
            F,
            T...
        >
    { };
} // end namespace lambda_detail


}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LAMBDA_HPP
