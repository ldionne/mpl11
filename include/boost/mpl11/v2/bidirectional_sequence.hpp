/*!
 * @file
 * Defines `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/bidirectional_sequence.hpp>

#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/fwd/forward_sequence.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct BidirectionalSequence { }; }

    namespace detail {
        template <typename S>
        struct check_usage<init<S>> {
            static_assert(!is_empty<S>::value,
            "Invalid usage of `init` on an empty sequence.");
        };

        template <typename S>
        struct check_usage<last<S>> {
            static_assert(!is_empty<S>::value,
            "Invalid usage of `last` on an empty sequence.");
        };
    } // end namespace detail

    template <typename S>
    struct init : private BOOST_MPL11_CHECK_USAGE(init<S>) {
        using type = typename BidirectionalSequence<typename tag_of<S>::type>
                     ::template init_impl<S>::type;
    };

    template <typename S>
    struct last : private BOOST_MPL11_CHECK_USAGE(last<S>) {
        using type = typename BidirectionalSequence<typename tag_of<S>::type>
                     ::template last_impl<S>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
