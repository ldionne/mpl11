/*!
 * @file
 * Defines `boost::mpl11::view::empty`.
 */

#ifndef BOOST_MPL11_VIEW_EMPTY_HPP
#define BOOST_MPL11_VIEW_EMPTY_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/empty_fwd.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct dispatch<tag::begin, view::empty>
        : begin<view::bounded_by<uint<0>, uint<0>>>
    { };

    template <>
    struct dispatch<tag::end, view::empty>
        : end<view::bounded_by<uint<0>, uint<0>>>
    { };

    template <>
    struct dispatch<tag::category_of, view::empty>
        : category_of<view::bounded_by<uint<0>, uint<0>>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_EMPTY_HPP
