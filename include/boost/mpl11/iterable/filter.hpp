/*!
 * @file
 * Defines `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_ITERABLE_FILTER_HPP
#define BOOST_MPL11_ITERABLE_FILTER_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/iterable/drop_while.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename Pred, typename S>
    struct filter { using type = filter; };

    template <typename Pred, typename S>
    struct tag_of<filter<Pred, S>> { using type = iterable_tag; };

    template <typename Pred, typename S>
    struct sequence_traits<filter<Pred, S>> {
        static constexpr bool has_O1_length = false;
        static constexpr bool has_O1_unpack = false;
        static constexpr bool is_finite = sequence_traits<S>::is_finite;
    };

    template <typename Pred, typename S>
    struct head_impl<filter<Pred, S>> {
        using type = typename head<
            typename drop_while<compose<quote<not_>, Pred>, S>::type
        >::type;
    };

    template <typename Pred, typename S>
    struct tail_impl<filter<Pred, S>> {
        using type = filter<
            Pred,
            typename tail<
                typename drop_while<compose<quote<not_>, Pred>, S>::type
            >::type
        >;
    };

    template <typename Pred, typename S>
    struct is_empty_impl<filter<Pred, S>>
        : is_empty<typename drop_while<compose<quote<not_>, Pred>, S>::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_FILTER_HPP
