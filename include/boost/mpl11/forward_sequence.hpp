/*!
 * @file
 * Defines `boost::mpl11::ForwardSequence`.
 */

#ifndef BOOST_MPL11_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/fwd/forward_sequence.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/sequence.hpp>


namespace boost { namespace mpl11 {
    struct ForwardSequence : Sequence, Comparable, Orderable {
        /*!
         * Returns `mpl11::deref<mpl11::begin<Seq>::type>::type` if
         * `is_empty<Seq>::value` is `false`, and triggers a static
         * assertion otherwise.
         */
        template <typename Seq>
        struct front_impl {
            static_assert(!is_empty<Seq>::value,
            "Attempt to use `front` on an empty sequence.");

            using type = typename deref<typename begin<Seq>::type>::type;
        };

        //! Performs an element-wise comparison of the two sequences.
        template <typename Seq1, typename Seq2>
        struct equal_impl
            : detail::std_equal<
                typename begin<Seq1>::type, typename end<Seq1>::type,
                typename begin<Seq2>::type, typename end<Seq2>::type
            >
        { };

        //! Performs a lexicographical comparison of the two sequences.
        template <typename Seq1, typename Seq2>
        struct less_impl
            : detail::lexicographical_compare<
                typename begin<Seq1>::type, typename end<Seq1>::type,
                typename begin<Seq2>::type, typename end<Seq2>::type
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_SEQUENCE_HPP
