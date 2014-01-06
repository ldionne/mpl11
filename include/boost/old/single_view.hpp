/*!
 * @file
 * Defines `boost::mpl11::single_view`.
 */

#ifndef BOOST_MPL11_SINGLE_VIEW_HPP
#define BOOST_MPL11_SINGLE_VIEW_HPP

#include <boost/mpl11/fwd/single_view.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/transformed_view.hpp>


namespace boost { namespace mpl11 {
    namespace single_element_detail {
        template <typename Element>
        using view_impl = transformed_view<
            iterator_range<uint<0>, uint<1>>,
            always<Element>
        >;
    }

    template <typename Element>
    struct dispatch<tag::begin, single_view<Element>>
        : begin<single_element_detail::view_impl<Element>>
    { };

    template <typename Element>
    struct dispatch<tag::end, single_view<Element>>
        : end<single_element_detail::view_impl<Element>>
    { };

    template <typename Element>
    struct dispatch<tag::category_of, single_view<Element>>
        : category_of<single_element_detail::view_impl<Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SINGLE_VIEW_HPP
