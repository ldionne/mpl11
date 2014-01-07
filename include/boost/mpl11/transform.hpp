/*!
 * @file
 * Defines `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_TRANSFORM_HPP
#define BOOST_MPL11_TRANSFORM_HPP

#include <boost/mpl11/fwd/transform.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/sequence/sequence.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename S>
    struct transform { using type = transform; };

    template <typename F, typename S>
    struct tag_of<transform<F, S>> { using type = sequence_tag; };

    template <typename F, typename S>
    struct sequence_traits<transform<F, S>> : sequence_traits<S> { };


    template <typename F, typename S>
    struct head_impl<transform<F, S>> {
        using type = typename apply<F, typename head<S>::type>::type;
    };

    template <typename F, typename S>
    struct is_empty_impl<transform<F, S>>
        : is_empty<S>
    { };

    template <typename F, typename S>
    struct tail_impl<transform<F, S>> {
        using type = transform<F, typename tail<S>::type>;
    };

    template <typename F, typename S>
    struct length_impl<transform<F, S>>
        : length<S>
    { };

    namespace transform_detail {
        template <typename F, typename Dest>
        struct fast_map {
            template <typename ...Args>
            using apply = mpl11::apply<
                Dest, typename mpl11::apply<F, Args>::type...
            >;
        };
    }

    template <typename S, typename F, typename Dest>
    struct unpack_impl<transform<F, S>, Dest> {
        using type = typename unpack<
            S, transform_detail::fast_map<F, Dest>
        >::type;
    };

    template <typename F, typename S>
    struct last_impl<transform<F, S>> {
        using type = typename apply<F, typename last<S>::type>::type;
    };

    template <typename F, typename S>
    struct init_impl<transform<F, S>> {
        using type = transform<F, typename init<S>::type>;
    };

    template <typename F, typename S, detail::std_size_t Index>
    struct at_c_impl<transform<F, S>, Index> {
        using type = typename apply<F, typename at_c<S, Index>::type>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TRANSFORM_HPP
