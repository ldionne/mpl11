/*!
 * @file
 * Defines `boost::mpl11::iterator_range`.
 */

#ifndef BOOST_MPL11_ITERATOR_RANGE_HPP
#define BOOST_MPL11_ITERATOR_RANGE_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * View over a range of elements delimited by [`First`, `Last`).
     *
     * `iterator_range` is either a forward sequence, a bidirectional
     * sequence or a random access sequence, depending on the category
     * of the underlying iterators.
     */
    template <typename First, typename Last>
    struct iterator_range BOOST_MPL11_DOXYGEN_ONLY({ });

    template <typename First, typename Last>
    struct dispatch<tag::begin, iterator_range<First, Last>>
        : always<First>
    { };

    template <typename First, typename Last>
    struct dispatch<tag::end, iterator_range<First, Last>>
        : always<Last>
    { };

    namespace iterator_range_detail {
        auto pick_category(category::random_access_iterator*)
            -> category::random_access_sequence
        ;

        auto pick_category(category::bidirectional_iterator*)
            -> category::bidirectional_sequence
        ;

        auto pick_category(category::forward_iterator*)
            -> category::forward_sequence
        ;
    } // end namespace iterator_range_detail

    template <typename First, typename Last>
    struct dispatch<tag::category_of, iterator_range<First, Last>>
        : always<decltype(
            iterator_range_detail::pick_category(
                (typename category_of<First>::type*)nullptr
            )
        )>
    {
        static_assert(is_same<
            typename category_of<First>::type,
            typename category_of<Last>::type
        >::value,
        "Attempt to use `iterator_range<First, Last>` with `First` and "
        "`Last` iterators having different categories.");
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_RANGE_HPP
