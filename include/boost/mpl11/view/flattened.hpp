/*!
 * @file
 * Defines `boost::mpl11::view::flattened`.
 */

#ifndef BOOST_MPL11_VIEW_FLATTENED_HPP
#define BOOST_MPL11_VIEW_FLATTENED_HPP

#include <boost/mpl11/bool.hpp>              // for the default `Predicate`
#include <boost/mpl11/functional/always.hpp> //

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/view/flattened_fwd.hpp>
#include <boost/mpl11/view/joined.hpp>
#include <boost/mpl11/view/single_element.hpp>
#include <boost/mpl11/view/transformed.hpp>


namespace boost { namespace mpl11 {
    namespace flattened_detail {
        template <typename Sequence, typename Predicate>
        using view_impl = view::joined<
            view::transformed<
                Sequence,
                if_<apply_wrap<typename lambda<Predicate>::type, _1>,
                    _1, view::single_element<_1>
                >
            >
        >;
    } // end namespace flattened_detail

    template <typename Sequence, typename Predicate>
    struct dispatch<tag::begin, view::flattened<Sequence, Predicate>>
        : begin<flattened_detail::view_impl<Sequence, Predicate>>
    { };

    template <typename Sequence, typename Predicate>
    struct dispatch<tag::end, view::flattened<Sequence, Predicate>>
        : end<flattened_detail::view_impl<Sequence, Predicate>>
    { };

    template <typename Sequence, typename Predicate>
    struct dispatch<tag::category_of, view::flattened<Sequence, Predicate>>
        : identity<category::forward_sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_FLATTENED_HPP
