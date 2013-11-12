/*!
 * @file
 * Defines `boost::mpl11::AssociativeSequence`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/fwd/associative_sequence.hpp>

// Required by the forward declaration.
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/sequence.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
    namespace associative_sequence_detail {
        struct not_found;

        template <
            typename Seq1, typename Seq2,
            typename First = typename begin<Seq1>::type,
            typename Last = typename end<Seq1>::type,
            bool = equal<First, Last>::value
        >
        struct is_subset_of
            : true_
        { };

        template <typename Seq1, typename Seq2, typename First, typename Last>
        struct lazy_next_step
            : is_subset_of<Seq1, Seq2, typename next<First>::type, Last>
        { };

        struct equal_to_nothing {
            struct mpl_class {
                template <typename, typename>
                using equal_impl = false_;

                template <typename, typename>
                using not_equal_impl = true_;
            };
        };

        template <
            typename Seq1, typename Seq2,
            typename First, typename Last,
            typename Element = typename deref<First>::type,
            typename Key = typename key_of<Seq1, Element>::type,
            typename Value = typename value_of<Seq1, Element>::type
        >
        struct is_subset_of_impl
            : and_<
                equal<Value, typename at<Seq2, Key, equal_to_nothing>::type>,
                lazy_next_step<Seq1, Seq2, First, Last>
            >
        { };

        template <typename Seq1, typename Seq2, typename First, typename Last>
        struct is_subset_of<Seq1, Seq2, First, Last, false>
            : is_subset_of_impl<Seq1, Seq2, First, Last>
        { };
    } // end namespace associative_sequence_detail

    template <typename S, typename Key>
    struct AssociativeSequence::at_impl<S, Key>
        : at<S, Key, associative_sequence_detail::not_found>
    {
        static_assert(
            !detail::is_same<
                typename at_impl::type,
                associative_sequence_detail::not_found
            >::value,
        "Could not find the value associated to the given key in an "
        "associative sequence and no default return value was specified.");
    };

    template <typename S1, typename S2>
    struct AssociativeSequence::equal_impl
        : and_<
            equal<typename size<S1>::type, typename size<S2>::type>,
            associative_sequence_detail::is_subset_of<S1, S2>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_SEQUENCE_HPP
