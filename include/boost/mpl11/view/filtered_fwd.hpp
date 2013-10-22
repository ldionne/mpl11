/*!
 * @file
 * Forward declares `boost::mpl11::view::filtered`.
 */

#ifndef BOOST_MPL11_VIEW_FILTERED_FWD_HPP
#define BOOST_MPL11_VIEW_FILTERED_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View into the subset of elements of `Sequence` satisfying `Predicate`.
     *
     * Regardless of the category of the underlying sequence, `filtered`
     * is only a @ref ForwardSequence.
     */
    template <typename Sequence, typename Predicate>
    struct filtered BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_FILTERED_FWD_HPP
