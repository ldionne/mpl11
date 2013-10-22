/*!
 * @file
 * Forward declares `boost::mpl11::view::sliced`.
 */

#ifndef BOOST_MPL11_VIEW_SLICED_FWD_HPP
#define BOOST_MPL11_VIEW_SLICED_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View over the subset of elements of a sequence contained in the range
     * of indices [`From`, `To`).
     *
     * The category of `sliced` depends on the category of the iterators
     * of the underlying `Sequence`.
     */
    template <typename Sequence, typename From, typename To>
    struct sliced BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_SLICED_FWD_HPP
