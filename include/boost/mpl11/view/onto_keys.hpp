/*!
 * @file
 * Defines `boost::mpl11::view::onto_keys`.
 */

#ifndef BOOST_MPL11_VIEW_ONTO_KEYS_HPP
#define BOOST_MPL11_VIEW_ONTO_KEYS_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/view/onto_keys_fwd.hpp>
#include <boost/mpl11/view/transformed.hpp>


namespace boost { namespace mpl11 {
    namespace onto_keys_detail {
        template <typename Sequence>
        using view_impl = view::transformed<
            Sequence, key_of<Sequence, _1>
        >;
    }

    template <typename Sequence>
    struct dispatch<tag::begin, view::onto_keys<Sequence>>
        : begin<onto_keys_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::end, view::onto_keys<Sequence>>
        : end<onto_keys_detail::view_impl<Sequence>>
    { };

    template <typename Sequence>
    struct dispatch<tag::category_of, view::onto_keys<Sequence>>
        : category_of<onto_keys_detail::view_impl<Sequence>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_ONTO_KEYS_HPP
