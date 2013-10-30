/*!
 * @file
 * Defines `boost::mpl11::AssociativeSequence`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/fwd/associative_sequence.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/sequence.hpp>
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

    struct AssociativeSequence : Sequence, Comparable {
        /*!
         * Returns `mpl11::at<Seq, Key, X>::type`, where `X` is such that a
         * compile-time assertion is triggered if `X` is returned.
         */
        template <
            typename Seq, typename Key, typename Default = detail::optional
        >
        struct at_impl
            : at<Seq, Key, associative_sequence_detail::not_found>
        {
            static_assert(
                !detail::is_same<
                    typename at_impl::type,
                    associative_sequence_detail::not_found
                >::value,
            "Could not find the value associated to a given key in an "
            "associative sequence and no default return value was specified.");
        };

        //! This operation must be provided by the user.
        template <typename Seq, typename Key>
        struct at_impl<Seq, Key> BOOST_MPL11_DOXYGEN_ONLY({ });

        //! This operation must be provided by the user.
        template <typename Seq, typename Key>
        struct has_key_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename Element>
        struct key_of_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename Element>
        struct value_of_impl;

        /*!
         * Returns whether both sequences have the same size and the same
         * keys mapping to equal values.
         */
        template <typename Seq1, typename Seq2>
        struct equal_impl
            : and_<
                equal<typename size<Seq1>::type, typename size<Seq2>::type>,
                associative_sequence_detail::is_subset_of<Seq1, Seq2>
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_SEQUENCE_HPP
