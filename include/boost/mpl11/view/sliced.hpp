/*!
 * @file
 * Defines `boost::mpl11::view::sliced`.
 */

#ifndef BOOST_MPL11_VIEW_SLICED_HPP
#define BOOST_MPL11_VIEW_SLICED_HPP

#include <boost/mpl11/algorithm/advance.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace sliced_detail {
    template <typename Sequence, typename From, typename To>
    struct check_indices {
        static_assert(0 <= From::value,
        "Attempt to use `sliced<Sequence, From, To>` with a "
        "negative `From` index.");

        static_assert(From::value <= To::value,
        "Attempt to use `sliced<Sequence, From, To>` with a `From` "
        "index greater than the `To` index.");

        static_assert(To::value <= size<Sequence>::type::value,
        "Attempt to use `sliced<Sequence, From, To>` with a `To` "
        "index greater than the size of the `Sequence`.");
    };
} // end namespace sliced_detail

namespace view {
    /*!
     * @ingroup view
     *
     * View over the subset of elements of a sequence contained in the range
     * of indices [`From`, `To`).
     *
     * The category of `sliced` depends on the category of the iterators
     * of the underlying `Sequence`.
     */
    template <typename Sequence, typename From, typename To>
    struct sliced BOOST_MPL11_DOXYGEN_ONLY({ });
} // end namespace view

template <
    typename OperationTag,
    typename Sequence, typename From, typename To,
    typename ...Args
>
struct dispatch<OperationTag, view::sliced<Sequence, From, To>, Args...>
    : sliced_detail::check_indices<Sequence, From, To>,
      dispatch<
        OperationTag,
        view::bounded_by<
            typename algorithm::advance<
                typename intrinsic::begin<Sequence>::type, From
            >::type,
            typename algorithm::advance<
                typename intrinsic::begin<Sequence>::type, To
            >::type
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_SLICED_HPP
