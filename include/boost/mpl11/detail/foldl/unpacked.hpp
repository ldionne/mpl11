/*!
 * @file
 * Defines `boost::mpl11::detail::unpacked_foldl`.
 */

#ifndef BOOST_MPL11_DETAIL_FOLDL_UNPACKED_HPP
#define BOOST_MPL11_DETAIL_FOLDL_UNPACKED_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Implements a recursive left-fold algorithm that first unpacks the
     * sequence before it performs the fold.
     *
     * Unpacking the sequence allows us to remove our reliance on iterators,
     * which turns out to be much more efficient.
     */
    template <typename Sequence, typename State, typename F>
    struct unpacked_foldl;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/unpack.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace unpacked_foldl_detail {
    template <bool Done>
    struct until_unpacked {
        template <typename State, typename F, typename Head, typename ...Tail>
        using apply = typename until_unpacked<(sizeof...(Tail) == 0)>::
                      template apply<apply_t<F, State, Head>, F, Tail...>;
    };

    template <>
    struct until_unpacked<true> {
        template <typename State, typename F>
        struct apply {
            using type = State;
        };
    };

    template <typename State, typename F>
    struct impl {
        template <typename ...T>
        using apply = typename until_unpacked<sizeof...(T) == 0>::
                      template apply<State, F, T...>;
    };
} // end namespace unpacked_foldl_detail

template <typename Sequence, typename State, typename F>
struct unpacked_foldl
    : unpack<Sequence, unpacked_foldl_detail::impl<State, F>>
{ };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FOLDL_UNPACKED_HPP
