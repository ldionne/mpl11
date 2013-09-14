/*!
 * @file
 * Defines `boost::mpl11::view::reversed`.
 */

#ifndef BOOST_MPL11_VIEW_REVERSED_HPP
#define BOOST_MPL11_VIEW_REVERSED_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     *
     * View onto the elements of a sequence, in reverse order.
     */
    template <typename Sequence>
    struct reversed BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view


#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/iterator/reverse.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
template <typename Operation, typename Sequence, typename ...Args>
struct dispatch<Operation, view::reversed<Sequence>, Args...>
    : dispatch<
        Operation,
        view::bounded_by<
            iterator::reverse<typename end<Sequence>::type>,
            iterator::reverse<typename begin<Sequence>::type>
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_REVERSED_HPP
