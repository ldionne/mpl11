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
#include <boost/mpl11/at_key.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/identity.hpp>
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
            typename First = begin_t<Seq1>,
            typename Last = end_t<Seq1>,
            bool = equal<First, Last>::value
        >
        struct is_subset_of
            : true_
        { };

        template <typename Seq1, typename Seq2, typename First, typename Last>
        struct lazy_next_step
            : is_subset_of<Seq1, Seq2, next_t<First>, Last>
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
            typename Element = deref_t<First>,
            typename Key = key_of_t<Seq1, Element>,
            typename Value = value_of_t<Seq1, Element>
        >
        struct is_subset_of_impl
            : and_<
                equal<
                    // IMPORTANT: The comparison must be made in this
                    // direction, i.e. with the potential equal_to_nothing
                    // on the left so that we use equal_to_nothing's
                    // comparison operator instead of Value's.
                    at_key_t<Seq2, Key, identity<equal_to_nothing>>, Value
                >,
                lazy_next_step<Seq1, Seq2, First, Last>
            >
        { };

        template <typename Seq1, typename Seq2, typename First, typename Last>
        struct is_subset_of<Seq1, Seq2, First, Last, false>
            : is_subset_of_impl<Seq1, Seq2, First, Last>
        { };

        template <bool AlwaysFalse = false>
        struct no_such_key {
            static_assert(AlwaysFalse,
            "Could not find the value associated to the given key in an "
            "associative sequence and no default return value was specified.");
        };
    } // end namespace associative_sequence_detail

    template <typename S, typename Key>
    struct AssociativeSequence::at_key_impl
        : at_key<S, Key, associative_sequence_detail::no_such_key<>>
    { };

    template <typename S1, typename S2>
    struct AssociativeSequence::equal_impl
        : and_<
            equal<size_t<S1>, size_t<S2>>,
            associative_sequence_detail::is_subset_of<S1, S2>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_SEQUENCE_HPP
