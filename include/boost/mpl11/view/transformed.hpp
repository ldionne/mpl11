/*!
 * @file
 * Defines `boost::mpl11::view::transformed`.
 */

#ifndef BOOST_MPL11_VIEW_TRANSFORMED_HPP
#define BOOST_MPL11_VIEW_TRANSFORMED_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     *
     * View over a `Sequence`'s elements transformed by the
     * application of `F`.
     *
     * The category of `transformed` depends on the category of
     * the underlying `Sequence`.
     */
    template <typename Sequence, typename F>
    struct transformed BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view


#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/iterator/transform.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
template <typename Op, typename Sequence, typename F, typename ...Args>
struct dispatch<Op, view::transformed<Sequence, F>, Args...>
    : dispatch<
        Op,
        view::bounded_by<
            iterator::transform<typename begin<Sequence>::type, F>,
            iterator::transform<typename end<Sequence>::type, F>
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_TRANSFORMED_HPP
