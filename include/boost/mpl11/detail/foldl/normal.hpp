/*!
 * @file
 * Defines `boost::mpl11::detail::normal_foldl`.
 */

#ifndef BOOST_MPL11_DETAIL_FOLDL_NORMAL_HPP
#define BOOST_MPL11_DETAIL_FOLDL_NORMAL_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Implements a recursive left-fold algorithm without optimizations.
     */
    template <typename Sequence, typename State, typename F>
    struct normal_foldl;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace normal_foldl_detail {
    template <bool Done>
    struct impl {
        template <
            typename F, typename State, typename First, typename Last,
            typename Next = next_t<First>
        >
        using apply = typename impl<equal<Next, Last>::value>::
            template apply<F, apply_t<F, State, deref_t<First>>, Next, Last>;
    };

    template <>
    struct impl<true> {
        template <typename F, typename State, typename First, typename Last>
        struct apply {
            using type = State;
        };
    };
} // end namespace normal_foldl_detail

template <typename Sequence, typename State, typename F>
struct normal_foldl
    : normal_foldl_detail::impl<
        equal<begin_t<Sequence>, end_t<Sequence>>::value
      >::template apply<F, State, begin_t<Sequence>, end_t<Sequence>>
{ };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_NORMAL_HPP
