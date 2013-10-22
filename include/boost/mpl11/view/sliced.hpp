/*!
 * @file
 * Defines `boost::mpl11::view::sliced`.
 */

#ifndef BOOST_MPL11_VIEW_SLICED_HPP
#define BOOST_MPL11_VIEW_SLICED_HPP

#include <boost/mpl11/algorithm/advance.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/sliced_fwd.hpp>


namespace boost { namespace mpl11 {
    namespace sliced_detail {
        template <typename Sequence, typename From, typename To>
        using view_impl = view::bounded_by<
            typename algorithm::advance<
                typename begin<Sequence>::type, From
            >::type,
            typename algorithm::advance<
                typename begin<Sequence>::type, To
            >::type
        >;

        template <typename Sequence, typename From, typename To>
        struct check_indices {
            static_assert(0 <= From::value,
            "Attempt to use `view::sliced<Sequence, From, To>` with a "
            "negative `From` index.");

            static_assert(From::value <= To::value,
            "Attempt to use `view::sliced<Sequence, From, To>` with a `From` "
            "index greater than the `To` index.");

            static_assert(To::value <= size<Sequence>::type::value,
            "Attempt to use `view::sliced<Sequence, From, To>` with a `To` "
            "index greater than the size of the `Sequence`.");
        };
    } // end namespace sliced_detail

    template <typename Sequence, typename From, typename To>
    struct dispatch<tag::begin, view::sliced<Sequence, From, To>>
        : sliced_detail::check_indices<Sequence, From, To>,
          begin<sliced_detail::view_impl<Sequence, From, To>>
    { };

    template <typename Sequence, typename From, typename To>
    struct dispatch<tag::end, view::sliced<Sequence, From, To>>
        : sliced_detail::check_indices<Sequence, From, To>,
          end<sliced_detail::view_impl<Sequence, From, To>>
    { };

    template <typename Sequence, typename From, typename To>
    struct dispatch<tag::category_of, view::sliced<Sequence, From, To>>
        : sliced_detail::check_indices<Sequence, From, To>,
          category_of<sliced_detail::view_impl<Sequence, From, To>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_SLICED_HPP
