/*!
 * @file
 * Defines `boost::mpl11::iterator_range`.
 */

#ifndef BOOST_MPL11_ITERATOR_RANGE_HPP
#define BOOST_MPL11_ITERATOR_RANGE_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Last>
    struct iterator_range;

    template <typename First, typename Last>
    struct dispatch<tag::begin, iterator_range<First, Last>>
        : always<First>
    { };

    template <typename First, typename Last>
    struct dispatch<tag::end, iterator_range<First, Last>>
        : always<Last>
    { };

    namespace iterator_range_detail {
        auto pick_category(tag::random_access<tag::iterator>*)
            -> tag::random_access<tag::sequence>
        ;

        auto pick_category(tag::bidirectional<tag::iterator>*)
            -> tag::bidirectional<tag::sequence>
        ;

        auto pick_category(tag::forward<tag::iterator>*)
            -> tag::forward<tag::sequence>
        ;
    } // end namespace iterator_range_detail

    template <typename First, typename Last>
    struct dispatch<tag::category_of, iterator_range<First, Last>>
        : always<decltype(iterator_range_detail::pick_category(
            (typename category_of<First>::type*)nullptr
        ))>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_RANGE_HPP
