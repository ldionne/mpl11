/*!
 * @file
 * Defines `boost::mpl11::value_view`.
 */

#ifndef BOOST_MPL11_VALUE_VIEW_HPP
#define BOOST_MPL11_VALUE_VIEW_HPP

#include <boost/mpl11/fwd/value_view.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/transformed_view.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
    namespace value_view_detail {
        template <typename Sequence>
        using view_impl = transformed_view<
            Sequence, value_of<Sequence, _1>
        >;
    }

    template <typename Sequence>
    struct dispatch<tag::begin, value_view<Sequence>>
        : begin<value_view_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::end, value_view<Sequence>>
        : end<value_view_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::category_of, value_view<Sequence>>
        : category_of<value_view_detail::view_impl<Sequence>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VALUE_VIEW_HPP
