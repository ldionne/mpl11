/*!
 * @file
 * Defines `boost::mpl11::view::empty`.
 */

#ifndef BOOST_MPL11_VIEW_EMPTY_HPP
#define BOOST_MPL11_VIEW_EMPTY_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/view/empty_fwd.hpp>


namespace boost { namespace mpl11 {
    namespace empty_view_detail { struct iterator; }

    template <>
    struct dispatch<tag::category_of, empty_view_detail::iterator>
        : identity<
            category::random_access_iterator
        >
    { };

    template <>
    struct dispatch<tag::begin, view::empty>
        : identity<empty_view_detail::iterator>
    { };

    template <>
    struct dispatch<tag::end, view::empty>
        : identity<empty_view_detail::iterator>
    { };

    template <>
    struct dispatch<tag::category_of, view::empty>
        : identity<
            category::random_access_sequence
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_EMPTY_HPP
