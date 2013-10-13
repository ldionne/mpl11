/*!
 * @file
 * Defines `boost::mpl11::flattened_view`.
 */

#ifndef BOOST_MPL11_FLATTENED_VIEW_HPP
#define BOOST_MPL11_FLATTENED_VIEW_HPP

#include <boost/mpl11/always.hpp>   // for the default `Predicate`
#include <boost/mpl11/bool.hpp>     //
#include <boost/mpl11/fwd/flattened_view.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/single_view.hpp>
#include <boost/mpl11/transformed_view.hpp>


namespace boost { namespace mpl11 {
    namespace flattened_detail {
        template <typename Sequence, typename Predicate>
        using view_impl = joined_view<
            transformed_view<
                Sequence,
                if_<apply_wrap<typename lambda<Predicate>::type, _1>,
                    _1, single_view<_1>
                >
            >
        >;
    } // end namespace flattened_detail

    template <typename Sequence, typename Predicate>
    struct dispatch<tag::begin, flattened_view<Sequence, Predicate>>
        : begin<flattened_detail::view_impl<Sequence, Predicate>>
    { };

    template <typename Sequence, typename Predicate>
    struct dispatch<tag::end, flattened_view<Sequence, Predicate>>
        : end<flattened_detail::view_impl<Sequence, Predicate>>
    { };

    template <typename Sequence, typename Predicate>
    struct dispatch<tag::category_of, flattened_view<Sequence, Predicate>>
        : identity<category::forward_sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FLATTENED_VIEW_HPP
