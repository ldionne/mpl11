/*!
 * @file
 * Forward declares `boost::mpl11::filtered_view`.
 */

#ifndef BOOST_MPL11_FWD_FILTERED_VIEW_HPP
#define BOOST_MPL11_FWD_FILTERED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View into the subset of elements of `Sequence` satisfying `Predicate`.
     *
     * Regardless of the category of the underlying sequence, `filtered_view`
     * is only a @ref ForwardSequence.
     */
    template <typename Sequence, typename Predicate>
    struct filtered_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FILTERED_VIEW_HPP
