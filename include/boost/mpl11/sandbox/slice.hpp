/*!
 * @file
 * Defines `boost::mpl11::slice`.
 */

#ifndef BOOST_MPL11_SLICE_HPP
#define BOOST_MPL11_SLICE_HPP

#include <boost/mpl11/fwd/slice.hpp>


namespace boost { namespace mpl11 {
namespace slice_detail {
    struct slice_class final : Sequence {

    };
} // end namespace slice_detail

template <typename Sequence, typename First, typename Last, typename Default>
struct class_of<slice<Sequence, First, Last>, Default> {
    using type = slice_detail::slice_class;
};

template <typename Sequence, typename First, typename Last>
struct slice
    : new_<Sequence, slice<Sequence, First, Last>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SLICE_HPP











/*!
 * @file
 * Defines `boost::mpl11::sliced_view`.
 */

#ifndef BOOST_MPL11_SLICED_VIEW_HPP
#define BOOST_MPL11_SLICED_VIEW_HPP

#include <boost/mpl11/fwd/sliced_view.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/size.hpp>


namespace boost { namespace mpl11 {
    namespace sliced_view_detail {
        template <typename Sequence, typename From, typename To>
        using view_impl = iterator_range<
            typename advance<
                typename begin<Sequence>::type, From
            >::type,
            typename advance<
                typename begin<Sequence>::type, To
            >::type
        >;

        template <typename Sequence, typename From, typename To>
        struct check_indices {
            static_assert(0 <= From::value,
            "Attempt to use `sliced_view<Sequence, From, To>` with a "
            "negative `From` index.");

            static_assert(From::value <= To::value,
            "Attempt to use `sliced_view<Sequence, From, To>` with a `From` "
            "index greater than the `To` index.");

            static_assert(To::value <= size<Sequence>::type::value,
            "Attempt to use `sliced_view<Sequence, From, To>` with a `To` "
            "index greater than the size of the `Sequence`.");
        };
    } // end namespace sliced_view_detail

    template <typename Sequence, typename From, typename To>
    struct dispatch<tag::begin, sliced_view<Sequence, From, To>>
        : sliced_view_detail::check_indices<Sequence, From, To>,
          begin<sliced_view_detail::view_impl<Sequence, From, To>>
    { };

    template <typename Sequence, typename From, typename To>
    struct dispatch<tag::end, sliced_view<Sequence, From, To>>
        : sliced_view_detail::check_indices<Sequence, From, To>,
          end<sliced_view_detail::view_impl<Sequence, From, To>>
    { };

    template <typename Sequence, typename From, typename To>
    struct dispatch<tag::category_of, sliced_view<Sequence, From, To>>
        : sliced_view_detail::check_indices<Sequence, From, To>,
          category_of<sliced_view_detail::view_impl<Sequence, From, To>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SLICED_VIEW_HPP
