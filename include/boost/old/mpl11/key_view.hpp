/*!
 * @file
 * Defines `boost::mpl11::key_view`.
 */

#ifndef BOOST_MPL11_KEY_VIEW_HPP
#define BOOST_MPL11_KEY_VIEW_HPP

#include <boost/mpl11/fwd/key_view.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/transformed_view.hpp>


namespace boost { namespace mpl11 {
    namespace key_view_detail {
        template <typename Sequence>
        using view_impl = transformed_view<
            Sequence, key_of<Sequence, _1>
        >;
    }

    template <typename Sequence>
    struct dispatch<tag::begin, key_view<Sequence>>
        : begin<key_view_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::end, key_view<Sequence>>
        : end<key_view_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::category_of, key_view<Sequence>>
        : category_of<key_view_detail::view_impl<Sequence>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_KEY_VIEW_HPP
