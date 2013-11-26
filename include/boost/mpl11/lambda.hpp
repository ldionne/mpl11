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
    template <typename ...Args>
    struct gather {
        //! @todo
        //! Use more general `join` once implemented: the result could be
        //! something else than a `vector`.
        template <typename State, typename T>
        using apply_multivalued = detail::vector_concat<
            State, apply_t<lambda<T>, Args...>
        >;

        template <typename State, typename T>
        using apply_single_valued = push_back<
            State, apply_t<lambda<T>, Args...>
        >;

        template <typename State, typename T>
        using apply = typename detail::tp_conditional<
            lambda<T>::is_multivalued,
            apply_multivalued,
            apply_single_valued
        >::template type<State, T>;
    };

    template <
        bool TriggersRecursiveEval, bool IsMultiValued,
        template <typename ...> class F, typename ...T>
    struct lambda_impl;

    template <template <typename ...> class F, typename ...T>
    struct lambda_impl<false, false, F, T...> {
        static constexpr bool triggers_recursive_eval = false;
        static constexpr bool is_multivalued = false;

        template <typename ...Args>
        using apply = identity<F<apply_t<lambda<T>, Args...>...>>;
    };

    template <template <typename ...> class F, typename ...T>
    struct lambda_impl<true, false, F, T...> {
        static constexpr bool triggers_recursive_eval = true;
        static constexpr bool is_multivalued = false;

        template <typename ...Args>
        using apply = F<apply_t<lambda<T>, Args...>...>;
    };

    template <template <typename ...> class F, typename ...T>
    struct lambda_impl<false, true, F, T...> {
        static constexpr bool triggers_recursive_eval = false;
        static constexpr bool is_multivalued = true;

        template <typename ...Args>
        using apply = unpack<
            foldl_t<vector<T...>, vector<>, gather<Args...>>,
            into<F>
        >;
    };

    template <template <typename ...> class F, typename ...T>
    struct lambda_impl<true, true, F, T...> {
        static constexpr bool triggers_recursive_eval = true;
        static constexpr bool is_multivalued = true;

        template <typename ...Args>
        using apply = unpack_t<
            foldl_t<vector<T...>, vector<>, gather<Args...>>,
            into<F>
        >;
    };
} // end namespace lambda_detail

template <typename T>
struct lambda {
    static constexpr bool is_multivalued = false;
    static constexpr bool triggers_recursive_eval = false;

    template <typename ...>
    using apply = identity<T>;
};

template <typename T>
struct lambda<lambda<T>> {
    static constexpr bool is_multivalued = false;
    static constexpr bool triggers_recursive_eval = false;

    template <typename ...>
    using apply = identity<lambda<T>>;
};

//! @todo Remove trailing `false`s once we're fixed on the arity of `or_`.
template <template <typename ...> class F, typename ...T>
struct lambda<F<T...>>
    : lambda_detail::lambda_impl<
        or_c<lambda<T>::triggers_recursive_eval..., false, false>::value,
        or_c<lambda<T>::is_multivalued..., false, false>::value,
        F,
        T...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LAMBDA_HPP
