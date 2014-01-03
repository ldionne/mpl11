/*!
 * @file
 * Defines `boost::mpl11::foldl`.
 */

#ifndef BOOST_MPL11_FOLDL_HPP
#define BOOST_MPL11_FOLDL_HPP

#include <boost/mpl11/fwd/foldl.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/sequence.hpp>


namespace boost { namespace mpl11 {
    namespace foldl_detail {
        template <typename F, typename State, typename Sequence,
            bool = is_empty<Sequence>::value>
        struct foldl_impl;

        template <typename F, typename State, typename Sequence>
        struct foldl_impl<F, State, Sequence, true> {
            using type = State;
        };

        template <typename F, typename State, typename Sequence>
        struct foldl_impl<F, State, Sequence, false> {
            using type = typename foldl_impl<
                F,
                typename apply<F, State, typename head<Sequence>::type>::type,
                typename tail<Sequence>::type
            >::type;
        };
    } // end namespace foldl_detail

    //! @todo Use a better algorithm.
    template <typename F, typename State, typename Sequence>
    struct foldl
        : foldl_detail::foldl_impl<F, State, Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDL_HPP
