/*!
 * @file
 * This file defines the `boost::mpl11::variadic` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VARIADIC_HPP
#define BOOST_MPL11_CONTAINER_VARIADIC_HPP

#include <boost/mpl11/algorithm_fwd.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/index_based_iterator.hpp>
#include <boost/mpl11/detail/O1_lookup.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic_fwd.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/size_t.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace variadic_detail {
struct forward_sequence;
struct bidirectional_sequence;
struct extensible_sequence;
struct front_extensible_sequence;
struct back_extensible_sequence;
struct associative_sequence;
struct extensible_associative_sequence;


// We will sometimes use this pack to perform some intermediate computations
// because we can't take for granted that the templates we're manipulating are
// actually variadic. All manipulations that would break with non-variadic
// templates will use this pack and transfer the result back at the end.
template <typename ...> struct pack;

template <typename DummyToMakeTheReturnValueDependent>
constexpr bool always_false() { return false; }

template <typename Semantics, typename Operation, typename Self, typename ...Args>
struct grand_dispatch {
    static_assert(always_false<Self>(),
    "using an operation that is not implemented for variadic sequences");
};


// intrinsic::begin
template <typename Semantics, typename Self>
struct grand_dispatch<Semantics, intrinsic::begin, Self> {
    using type = detail::index_based_iterator<Self, 0>;
};


// intrinsic::end
template <typename Semantics, template <typename ...> class M, typename ...T>
struct grand_dispatch<Semantics, intrinsic::end, M<T...>> {
    using type = detail::index_based_iterator<M<T...>, sizeof...(T)>;
};


// intrinsic::size
template <typename Semantics, template <typename ...> class M, typename ...T>
struct grand_dispatch<Semantics, intrinsic::size, M<T...>> {
    using type = size_t<sizeof...(T)>;
};


// intrinsic::empty
template <typename Semantics, template <typename ...> class M, typename ...T>
struct grand_dispatch<Semantics, intrinsic::empty, M<T...>> {
    using type = bool_<sizeof...(T) == 0>;
};


// intrinsic::front
template <typename Semantics, template <typename ...> class M, typename Head, typename ...Tail>
struct grand_dispatch<Semantics, intrinsic::front, M<Head, Tail...>> {
    using type = Head;
};

template <typename Semantics, template <typename ...> class M>
struct grand_dispatch<Semantics, intrinsic::front, M<>> {
    static_assert(always_false<M<>>(), "using `front` on an empty sequence");
};


// intrinsic::back
template <typename Head, typename ...Tail>
struct back_impl<Head, Tail...>
    : back_impl<Tail...>
{ };

template <typename Head>
struct back_impl<Head> {
    using type = Head;
};

template <typename Semantics, template <typename ...> class M, typename ...T>
struct grand_dispatch<Semantics, intrinsic::back, M<T...>>
    : back_impl<T...>
{ };

template <typename Semantics, template <typename ...> class M>
struct grand_dispatch<Semantics, intrinsic::back, M<>> {
    static_assert(always_false<M<>>(), "using `back` on an empty sequence");
};


// intrinsic::insert
template <typename Semantics, template <typename ...> class M, typename ...T, typename Position, typename Element>
struct grand_dispatch<Semantics, intrinsic::insert, M<T...>, Position, Element> {
    static_assert(false, "implement me");
};


// intrinsic::insert_range
template <typename Semantics, template <typename ...> class M, typename ...T, typename Position, typename Range>
struct grand_dispatch<Semantics, intrinsic::insert_range, M<T...>, Position, Range> {
    static_assert(false, "implement me");
};


// intrinsic::erase
template <typename Semantics, template <typename ...> class M, typename ...T, typename Position>
struct grand_dispatch<Semantics, intrinsic::erase, M<T...>, Position> {
    static_assert(false, "implement me");
};

template <typename Semantics, template <typename ...> class M, typename ...T, typename First, typename Last>
struct grand_dispatch<Semantics, intrinsic::erase, M<T...>, First, Last> {
    static_assert(false, "implement me");
};


// intrinsic::clear
template <typename Semantics, template <typename ...> class M, typename ...T>
struct grand_dispatch<Semantics, intrinsic::clear, M<T...>> {
    using type = M<>;
};


// intrinsic::push_front
template <typename Semantics, template <typename ...> class M, typename ...T, typename Element>
struct grand_dispatch<Semantics, intrinsic::push_front, M<T...>, Element> {
    using type = M<Element, T...>;
};


// intrinsic::pop_front
template <typename Semantics, template <typename ...> class M, typename Head, typename ...Tail>
struct grand_dispatch<Semantics, intrinsic::pop_front, M<Head, Tail...>> {
    using type = M<Tail...>;
};

template <typename Semantics, template <typename ...> class M>
struct grand_dispatch<Semantics, intrinsic::pop_front, M<>> {
    static_assert(always_false<M<>>(), "using `pop_front` on an empty sequence");
};


// intrinsic::push_back
template <typename Semantics, template <typename ...> class M, typename ...T, typename Element>
struct grand_dispatch<Semantics, intrinsic::push_back, M<T...>, Element> {
    using type = M<T..., Element>;
};


// intrinsic::pop_back
template <template <typename ...> class Result, typename Pack, typename ...T>
struct pop_back_impl;

template <template <typename ...> class Result, typename ...T, typename Head, typename ...Tail>
struct pop_back_impl<Result, pack<T...>, Head, Tail...>
    : pop_back_impl<Result, pack<T..., Head>, Tail...>
{ };

template <template <typename ...> class Result, typename ...T, typename Back>
struct pop_back_impl<Result, pack<T...>, Back> {
    using type = Result<T...>;
};

template <typename Semantics, template <typename ...> class M, typename ...T>
struct grand_dispatch<Semantics, intrinsic::pop_back, M<T...>>
    : pop_back_impl<M, pack<>, T...>
{ };

template <typename Semantics, template <typename ...> class M>
struct grand_dispatch<Semantics, intrinsic::pop_back, M<>> {
    static_assert(always_false<M<>>(), "using `pop_back` on an empty sequence");
};


// intrinsic::has_key
template <typename Semantics, template <typename ...> class M, typename ...T, typename Key>
struct grand_dispatch<Semantics, intrinsic::has_key, M<T...>, Key>
    : detail::O1_lookup<M<T...>, T...>::template has_key<Key>
{ };


// intrinsic::count
template <typename Semantics, template <typename ...> class M, typename ...T, typename Key>
struct grand_dispatch<Semantics, intrinsic::count, M<T...>, Key> {
    static_assert(false, "implement me");
};

// intrinsic::at_key
struct key_not_found;

template <typename Semantics, typename Self, typename Key>
struct grand_dispatch<Semantics, intrinsic::at_key, Self, Key>
    : grand_dispatch<associative_sequence, intrinsic::at_key, Self, Key, key_not_found>
{
    static_assert(!is_same<typename grand_dispatch::type, key_not_found>::value,
        "the requested key could not be found in the associative "
        "sequence and no default return value was specified");
};

template <template <typename ...> class M, typename ...T, typename Key, typename Default>
struct grand_dispatch<associative_sequence, intrinsic::at_key, M<T...>, Key, Default>
    : detail::O1_lookup<M<T...>, T...>::template at_key<Key, Default>
{ };


// intrinsic::insert
template <typename Self, typename Hint, typename Element>
struct grand_dispatch<associative_sequence, intrinsic::insert, Self, Hint, Element>
    : grand_dispatch<associative_sequence, intrinsic::insert, Self, Element>
{ };

template <template <typename ...> class M, typename ...T, typename Element>
struct grand_dispatch<associative_sequence, intrinsic::insert, M<T...>, Element> {
    using type = M<Element, T...>;
};


// intrinsic::erase_key
template <template <typename ...> class M, typename ...T, typename Key>
struct grand_dispatch<associative_sequence, intrinsic::erase_key, M<T...>, Key> {
    static_assert(false, "implement me");
};


//////////////////////////////////////////////////////////////////////////////
// algorithms
//////////////////////////////////////////////////////////////////////////////

// algorithm::transform
template <typename Semantics, template <typename ...> class M, typename ...T, typename F, typename Inserter>
struct grand_dispatch<Semantics, algorithm::transform, M<T...>, F, Inserter> {
    using type = M<typename apply<F, T>::type...>;
};


// algorithm::foldl
template <typename Semantics, template <typename ...> class M, typename State, typename BinaryOp>
struct grand_dispatch<Semantics, algorithm::foldl, M<>, State, BinaryOp> {
    using type = State;
};

template <typename Semantics, template <typename ...> class M, typename Head, typename ...Tail, typename State, typename BinaryOp>
struct grand_dispatch<Semantics, algorithm::foldl, M<Head, Tail...>, State, BinaryOp>
    : grand_dispatch<Semantics, algorithm::foldl,
        pack<Tail...>,
        typename apply<BinaryOp, State, Head>::type,
        BinaryOp
    >
{ };


// algorithm::foldr
template <typename Semantics, template <typename ...> class M, typename State, typename BinaryOp>
struct grand_dispatch<Semantics, algorithm::foldr, M<>, State, BinaryOp> {
    using type = State;
};

template <typename Semantics, template <typename ...> class M, typename Head, typename ...Tail, typename State, typename BinaryOp>
struct grand_dispatch<Semantics, algorithm::foldr, M<Head, Tail...>, State, BinaryOp>
    : apply<
        BinaryOp,
        typename grand_dispatch<Semantics, algorithm::foldr,
            pack<Tail...>, State, BinaryOp
        >::type,
        Head
    >
{ };


// algorithm::copy
template <typename Semantics, template <typename ...> class Source, typename ...Content, template <typename ...> class Destination>
struct grand_dispatch<Semantics, algorithm::copy, Source<Content...>, Destination<>> {
    using type = Destination<Content...>;
};


// algorithm::equal
template <typename Semantics, template <typename ...> class X, typename ...T, template <typename ...> class Y, typename ...U, typename BinaryPred>
struct grand_dispatch<Semantics, algorithm::equal, X<T...>, Y<U...>, BinaryPred>
    : and_<
        bool_<sizeof...(T) == sizeof...(U)>,
        apply<BinaryPred, T, U>...
    >
{ };


// algorithm::replace_if
template <typename Semantics, template <typename ...> class M, typename ...T, typename Pred, typename NewType>
struct grand_dispatch<Semantics, algorithm::replace_if, M<T...>, Pred, NewType> {
    using type = M<typename if_<apply<Pred, T>, NewType, T>::type...>;
};


// algorithm::replace
template <typename Semantics, template <typename ...> class M, typename ...T, typename OldType, typename NewType>
struct grand_dispatch<Semantics, algorithm::replace, M<T...>, OldType, NewType> {
    using type = M<typename if_<is_same<OldType, T>, NewType, T>::type...>;
};


// algorithm::all_of
template <typename Semantics, template <typename ...> class M, typename ...T, typename Pred>
struct grand_dispatch<Semantics, algorithm::all_of, M<T...>, Pred>
    : and_<apply<Pred, T>..., true_, true_> // at least 2 args to and_
{ };


// algorithm::any_of
template <typename Semantics, template <typename ...> class M, typename ...T, typename Pred>
struct grand_dispatch<Semantics, algorithm::any_of, M<T...>, Pred>
    : or_<apply<Pred, T>..., false_, false_> // at least 2 args to or_
{ };
} // end namespace variadic_detail

template <typename Semantics, typename Sequence>
struct variadic_sequence_dispatcher;

template <typename Semantics, template <typename ...> class M, typename ...T>
struct variadic_sequence_dispatcher<Semantics, M<T...>> {
    template <typename Operation, typename ...Args>
    using apply = variadic_detail::grand_dispatch<
        Semantics, Operation, M<T...>, Args...
    >;
};


template <typename ...Pairs>
class map {
    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply
            : variadic_sequence_dispatcher<associative_sequence, map>::
                template apply<Operation, Args...>
        { };

        template <typename Pair>
        struct apply<intrinsic::key_type, Pair>
            : first<Pair>
        { };

        template <typename Pair>
        struct apply<intrinsic::value_type, Pair>
            : second<Pair>
        { };
    };

public:
    struct mpl11 {
        using dispatcher = implementation;
    };
};


template <typename ...Elements>
class set {
    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply
            : variadic_sequence_dispatcher<associative_sequence, set>::
                template apply<Operation, Args...>
        { };

        template <typename Element>
        struct apply<intrinsic::key_type, Element> {
            using type = Element;
        };

        template <typename Element>
        struct apply<intrinsic::value_type, Element> {
            using type = Element;
        };
    };

public:
    struct mpl11 {
        using dispatcher = implementation;
    };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_VARIADIC_HPP
