/*!
 * @file
 * Defines `boost::mpl11::empty_sequence`.
 */

#ifndef BOOST_MPL11_EMPTY_SEQUENCE_HPP
#define BOOST_MPL11_EMPTY_SEQUENCE_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    namespace empty_sequence_detail { struct begin_end; }

    //! Random access sequence containing no elements.
    struct empty_sequence BOOST_MPL11_DOXYGEN_ONLY({ });

    template <>
    struct dispatch<tag::begin, empty_sequence>
        : always<empty_sequence_detail::begin_end>
    { };

    template <>
    struct dispatch<tag::end, empty_sequence>
        : always<empty_sequence_detail::begin_end>
    { };

    template <>
    struct dispatch<tag::category_of, empty_sequence>
        : always<category::random_access_sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EMPTY_SEQUENCE_HPP
