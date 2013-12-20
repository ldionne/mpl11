/*!
 * @file
 * Defines `boost::mpl11::drop` and `boost::mpl11::drop_c`.
 */

#ifndef BOOST_MPL11_DROP_HPP
#define BOOST_MPL11_DROP_HPP

#include <boost/mpl11/fwd/drop.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/detail/optim.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/fwd/vector.hpp>
#include <boost/mpl11/integral_c.hpp> // required for fwd/drop.hpp
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/repeat.hpp>
#include <boost/mpl11/size.hpp>


namespace boost { namespace mpl11 {
namespace drop_detail {
    template <typename N>
    struct assert_usage {
        static_assert(N::value >= 0,
        "Invalid usage of `drop`: `N::value` must be non-negative.");
    };

    template <
        detail::std_size_t N, typename Sequence,
        bool = N >= size<Sequence>::value
    >
    struct begin_impl;

    template <detail::std_size_t N, typename Sequence>
    struct begin_impl<N, Sequence, false>
        : advance_c<typename begin<Sequence>::type, N>
    { };

    template <detail::std_size_t N, typename Sequence>
    struct begin_impl<N, Sequence, true>
        : end<Sequence>
    { };
} // end namespace drop_detail

template <typename N, typename Sequence>
struct drop
    : apply<new_<Sequence>, drop<N, Sequence>>
{ };

/////////////////////////////////
// Sequence
/////////////////////////////////
template <typename N, typename Sequence>
struct begin<drop<N, Sequence>>
    : drop_detail::assert_usage<N>,
      drop_detail::begin_impl<N::value, Sequence>
{ };

template <typename N, typename Sequence>
struct end<drop<N, Sequence>>
    : drop_detail::assert_usage<N>,
      end<Sequence>
{ };

template <typename N, typename Sequence>
struct size<drop<N, Sequence>>
    : drop_detail::assert_usage<N>,
      integral_c<detail::std_size_t,
        (
            N::value >= size<Sequence>::value
                ? 0
                : size<Sequence>::value - N::value
        )
      >
{ };

template <typename N, typename Sequence>
struct is_empty<drop<N, Sequence>>
    : drop_detail::assert_usage<N>,
      bool_<(N::value >= size<Sequence>::value)>
{ };

/////////////////////////////////
// Other specializations
/////////////////////////////////
namespace drop_detail {
    template <
        detail::std_size_t N, typename Sequence, typename F,
        detail::optim =
            detail::optims_of<Sequence>::value & detail::optim::O1_unpack
    >
    struct unpack_impl;

    template <typename F, typename Ignore>
    struct variadic_unpack;

    template <typename F, typename ...Head>
    struct variadic_unpack<F, vector<Head...>> {
        template <typename ...Tail>
        static auto apply_tail(Head..., detail::no_decay<Tail>*...)
            -> mpl11::apply<F, Tail...>;

        template <typename ...Args>
        using apply = decltype(
            apply_tail((detail::no_decay<Args>*)nullptr...)
        );
    };

    template <detail::std_size_t N, typename Sequence, typename F>
    struct unpack_impl<N, Sequence, F, detail::optim::O1_unpack>
        : unpack<
            Sequence,
            variadic_unpack<F, typename repeat_c<void*, N>::type>
        >
    { };

    template <detail::std_size_t N, typename Sequence, typename F>
    struct unpack_impl<N, Sequence, F, detail::optim::none>
        : unpack<
            iterator_range<
                typename begin_impl<N, Sequence>::type,
                typename end<Sequence>::type
            >,
            F
        >
    { };
} // end namespace drop_detail

template <typename N, typename Sequence, typename F>
struct unpack<drop<N, Sequence>, F>
    : drop_detail::assert_usage<N>,
      drop_detail::unpack_impl<N::value, Sequence, F>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DROP_HPP
