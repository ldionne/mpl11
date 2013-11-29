/*!
 * @file
 * Defines `boost::mpl11::iterator_range`.
 */

#ifndef BOOST_MPL11_ITERATOR_RANGE_HPP
#define BOOST_MPL11_ITERATOR_RANGE_HPP

#include <boost/mpl11/fwd/iterator_range.hpp>

#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/random_access_sequence.hpp>


namespace boost { namespace mpl11 {
    namespace iterator_range_detail {
        struct iterator_range_class final : RandomAccessSequence {
            template <typename Sequence> struct begin_impl;
            template <typename Sequence> struct end_impl;

            template <typename First, typename Last>
            struct begin_impl<iterator_range<First, Last>> {
                using type = First;
            };

            template <typename First, typename Last>
            struct end_impl<iterator_range<First, Last>> {
                using type = Last;
            };
        };
    } // end namespace iterator_range_detail

    template <typename First, typename Last, typename Default>
    struct class_of<iterator_range<First, Last>, Default> {
        using type = iterator_range_detail::iterator_range_class;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_RANGE_HPP
