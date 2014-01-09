/*!
 * @file
 * Defines `boost::mpl11::detail::sequence_map`.
 */

#ifndef BOOST_MPL11_DETAIL_SEQUENCE_MAP_HPP
#define BOOST_MPL11_DETAIL_SEQUENCE_MAP_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Lazy iterable mapping a metafunction class over another iterable.
     */
    template <typename F, typename S>
    struct sequence_map;
}}}


#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename S>
    struct tag_of<detail::sequence_map<F, S>> {
        using type = iterable_tag;
    };

    template <typename F, typename S>
    struct sequence_traits<detail::sequence_map<F, S>>
        : sequence_traits<S>
    { };


    template <typename F, typename S>
    struct head_impl<detail::sequence_map<F, S>> {
        using type = typename apply<F, typename head<S>::type>::type;
    };

    template <typename F, typename S>
    struct is_empty_impl<detail::sequence_map<F, S>>
        : is_empty<S>
    { };

    template <typename F, typename S>
    struct tail_impl<detail::sequence_map<F, S>> {
        using type = detail::sequence_map<F, typename tail<S>::type>;
    };

    template <typename F, typename S>
    struct length_impl<detail::sequence_map<F, S>>
        : length<S>
    { };

    namespace sequence_map_detail {
        template <typename F, typename Dest>
        struct fast_map {
            template <typename ...Args>
            using apply = mpl11::apply<
                Dest, typename mpl11::apply<F, Args>::type...
            >;
        };
    }

    template <typename S, typename F, typename Dest>
    struct unpack_impl<detail::sequence_map<F, S>, Dest> {
        using type = typename unpack<
            S, sequence_map_detail::fast_map<F, Dest>
        >::type;
    };

    template <typename F, typename S>
    struct last_impl<detail::sequence_map<F, S>> {
        using type = typename apply<F, typename last<S>::type>::type;
    };

    template <typename F, typename S>
    struct init_impl<detail::sequence_map<F, S>> {
        using type = detail::sequence_map<F, typename init<S>::type>;
    };

    template <typename F, typename S, detail::std_size_t Index>
    struct at_c_impl<detail::sequence_map<F, S>, Index> {
        using type = typename apply<F, typename at_c<S, Index>::type>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_SEQUENCE_MAP_HPP
