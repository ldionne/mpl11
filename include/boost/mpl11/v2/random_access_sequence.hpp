/*!
 * @file
 * Defines `boost::mpl11::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/fwd/random_access_sequence.hpp>

#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/fwd/finite_sequence.hpp>
#include <boost/mpl11/integral_c.hpp> // required by the forward declaration
#include <boost/mpl11/sequence_traits.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct RandomAccessSequence { }; }

    namespace detail {
        template <typename S, typename Index>
        struct check_usage<at<S, Index>> {
        private:
            static_assert(Index::value >= 0,
            "Invalid usage of `at`: "
            "Accessing a sequence at a negative index.");


            using Length = typename conditional<sequence_traits<S>::is_finite,
                length<S>, size_t<Index::value + 1>
            >::type;

            static_assert(Index::value < Length::value,
            "Invalid usage of `at`: "
            "Accessing a sequence at an out-of-bounds index.");
        };

        template <typename S, typename Start, typename Stop>
        struct check_usage<slice<S, Start, Stop>> {
        private:
            static_assert(Start::value >= 0,
            "Invalid usage of `slice`: "
            "Start and Stop indices must be non-negative.");

            static_assert(Start::value <= Stop::value,
            "Invalid usage of `slice`: "
            "Start index greater than the Stop index.");


            using Length = typename conditional<sequence_traits<S>::is_finite,
                length<S>, Stop
            >::type;

            static_assert(Stop::value <= Length::value,
            "Invalid usage of `slice`: "
            "Stop index out of the bounds of the sliced sequence.");
        };
    } // end namespace detail

    template <typename S, typename Start, typename Stop>
    struct slice : private BOOST_MPL11_CHECK_USAGE(slice<S, Start, Stop>) {
        using type = typename RandomAccessSequence<typename tag_of<S>::type>
                     ::template slice_impl<S, Start, Stop>::type;
    };

    template <typename S, typename Index>
    struct at : private BOOST_MPL11_CHECK_USAGE(at<S, Index>) {
        using type = typename RandomAccessSequence<typename tag_of<S>::type>
                     ::template at_impl<S, Index>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP
