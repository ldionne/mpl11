/*!
 * @file
 * Defines `boost::mpl11::view::single_element`.
 */

#ifndef BOOST_MPL11_VIEW_SINGLE_ELEMENT_HPP
#define BOOST_MPL11_VIEW_SINGLE_ELEMENT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/always.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/transformed.hpp>


namespace boost { namespace mpl11 {
    namespace single_element_detail {
        template <typename Element>
        using view_impl = view::transformed<
            view::bounded_by<uint<0>, uint<1>>,
            always<Element>
        >;
    }

    template <typename Element>
    struct dispatch<tag::begin, view::single_element<Element>>
        : begin<single_element_detail::view_impl<Element>>
    { };

    template <typename Element>
    struct dispatch<tag::end, view::single_element<Element>>
        : end<single_element_detail::view_impl<Element>>
    { };

    template <typename Element>
    struct dispatch<tag::category_of, view::single_element<Element>>
        : category_of<single_element_detail::view_impl<Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_SINGLE_ELEMENT_HPP
