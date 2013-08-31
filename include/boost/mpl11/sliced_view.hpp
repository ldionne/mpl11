/*!
 * @file
 * Defines `boost::mpl11::sliced_view`.
 */

#ifndef BOOST_MPL11_SLICED_VIEW_HPP
#define BOOST_MPL11_SLICED_VIEW_HPP

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/size.hpp>


namespace boost { namespace mpl11 {
namespace sliced_view_detail {
    template <typename Sequence, typename From, typename To>
    struct check_indices {
        static_assert(0 <= From::type::value,
        "Attempt to use `sliced_view<Sequence, From, To>` with a "
        "negative `From` index.");

        static_assert(From::type::value <= To::type::value,
        "Attempt to use `sliced_view<Sequence, From, To>` with a `From` "
        "index greater than the `To` index.");

        static_assert(To::type::value <= size<Sequence>::type::value,
        "Attempt to use `sliced_view<Sequence, From, To>` with a `To` "
        "index greater than the size of the `Sequence`.");
    };
} // end namespace sliced_view_detail

/*!
 * View over the subset of elements of a sequence contained in the range
 * of indices [`From`, `To`).
 *
 * The category of `sliced_view` depends on the category of the iterators
 * of the underlying `Sequence`.
 */
template <typename Sequence, typename From, typename To>
struct sliced_view BOOST_MPL11_DOXYGEN_ONLY({ });

template <
    typename OperationTag,
    typename Sequence, typename From, typename To,
    typename ...Args
>
struct dispatch<OperationTag, sliced_view<Sequence, From, To>, Args...>
    : sliced_view_detail::check_indices<Sequence, From, To>,
      dispatch<
        OperationTag,
        iterator_range<
            typename advance<typename begin<Sequence>::type, From>::type,
            typename advance<typename begin<Sequence>::type, To>::type
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SLICED_VIEW_HPP
