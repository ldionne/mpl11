/*!
 * @file
 * Defines `boost::mpl11::repeat`.
 */

#ifndef BOOST_MPL11_REPEAT_HPP
#define BOOST_MPL11_REPEAT_HPP

#include <boost/mpl11/fwd/repeat.hpp>

#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/fwd/bidirectional_sequence.hpp>
#include <boost/mpl11/fwd/forward_sequence.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/take.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct tag_of<repeat<T>> {
        using type = random_access_sequence_tag;
    };

    // ForwardSequence
    template <typename T>
    struct head<repeat<T>> {
        using type = T;
    };

    template <typename T>
    struct tail<repeat<T>> {
        using type = repeat<T>;
    };

    template <typename T>
    struct is_empty<repeat<T>>
        : false_
    { };

    // BidirectionalSequence
    template <typename T>
    struct last<repeat<T>> {
        using type = T;
    };

    template <typename T>
    struct init<repeat<T>> {
        using type = repeat<T>;
    };

    // RandomAccessSequence
    template <typename T, typename Index>
    struct at<repeat<T>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at<repeat<T>, Index>)
    {
        using type = T;
    };

    template <typename T, typename Start, typename Stop>
    struct slice<repeat<T>, Start, Stop>
        : private BOOST_MPL11_CHECK_USAGE(slice<repeat<T>, Start, Stop>)
    {
        using type = take_c<Stop::value - Start::value, repeat<T>>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REPEAT_HPP
