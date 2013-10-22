/*!
 * @file
 * Defines `boost::mpl11::view::onto_values`.
 */

#ifndef BOOST_MPL11_VIEW_ONTO_VALUES_HPP
#define BOOST_MPL11_VIEW_ONTO_VALUES_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/intrinsic/value_of.hpp>
#include <boost/mpl11/view/onto_values_fwd.hpp>
#include <boost/mpl11/view/transformed.hpp>


namespace boost { namespace mpl11 {
    namespace onto_values_detail {
        template <typename Sequence>
        using view_impl = view::transformed<
            Sequence, value_of<Sequence, _1>
        >;
    }

    template <typename Sequence>
    struct dispatch<tag::begin, view::onto_values<Sequence>>
        : begin<onto_values_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::end, view::onto_values<Sequence>>
        : end<onto_values_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::category_of, view::onto_values<Sequence>>
        : category_of<onto_values_detail::view_impl<Sequence>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_ONTO_VALUES_HPP
