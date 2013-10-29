/*!
 * @file
 * Forward declares `boost::mpl11::sliced_view`.
 */

#ifndef BOOST_MPL11_FWD_SLICED_VIEW_HPP
#define BOOST_MPL11_FWD_SLICED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View over the subset of elements of a sequence contained in the range
     * of indices [`From`, `To`).
     *
     * The category of `sliced_view` depends on the category of the iterators
     * of the underlying `Sequence`.
     */
    template <typename Sequence, typename From, typename To>
    struct sliced_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SLICED_VIEW_HPP
