/*!
 * @file
 * Defines `boost::mpl11::empty_sequence`.
 */

#ifndef BOOST_MPL11_EMPTY_SEQUENCE_HPP
#define BOOST_MPL11_EMPTY_SEQUENCE_HPP

#include <boost/mpl11/fwd/empty_sequence.hpp>

#include <boost/mpl11/category/random_access_iterator.hpp>
#include <boost/mpl11/category/random_access_sequence.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    namespace empty_sequence_detail { struct iterator; }

    template <>
    struct dispatch<tag::category_of, empty_sequence_detail::iterator>
        : identity<
            category::random_access_iterator
        >
    { };

    template <>
    struct dispatch<tag::begin, empty_sequence>
        : identity<empty_sequence_detail::iterator>
    { };

    template <>
    struct dispatch<tag::end, empty_sequence>
        : identity<empty_sequence_detail::iterator>
    { };

    template <>
    struct dispatch<tag::category_of, empty_sequence>
        : identity<
            category::random_access_sequence
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EMPTY_SEQUENCE_HPP
