/*!
 * @file
 * Defines `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_TRANSFORM_HPP
#define BOOST_MPL11_TRANSFORM_HPP

#include <boost/mpl11/fwd/transform.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/fwd/head.hpp>
#include <boost/mpl11/fwd/init.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/last.hpp>
#include <boost/mpl11/fwd/length.hpp>
#include <boost/mpl11/fwd/slice.hpp>
#include <boost/mpl11/fwd/tail.hpp>
#include <boost/mpl11/fwd/unpack.hpp>


namespace boost { namespace mpl11 {
    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename F, typename S>
    struct is_empty<transform<F, S>>
        : is_empty<S>
    { };

    template <typename F, typename S>
    struct head<transform<F, S>>
        : apply<F, typename head<S>::type>
    { };

    template <typename F, typename S>
    struct tail<transform<F, S>> {
        using type = transform<F, typename tail<S>::type>;
    };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename F, typename S>
    struct length<transform<F, S>>
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
    struct unpack<transform<F, S>, Dest>
        : unpack<S, transform_detail::fast_map<F, Dest>>
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename F, typename S>
    struct last<transform<F, S>>
        : apply<F, typename last<S>::type>
    { };

    template <typename F, typename S>
    struct init<transform<F, S>> {
        using type = transform<F, typename init<S>::type>;
    };


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <typename F, typename S, typename Index>
    struct at<transform<F, S>, Index>
        : apply<F, typename at<S, Index>::type>
    { };

    template <typename F, typename S, typename Start, typename Stop>
    struct slice<transform<F, S>, Start, Stop> {
        using type = transform<F, typename slice<S, Start, Stop>::type>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TRANSFORM_HPP
