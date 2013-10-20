/*!
 * @file
 * Forward declares `boost::mpl11::flattened_view`.
 */

#ifndef BOOST_MPL11_FWD_FLATTENED_VIEW_HPP
#define BOOST_MPL11_FWD_FLATTENED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/fwd/always.hpp>
#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View of a sequence as the concatenation of all its elements
     * (seen as sequences themselves) satisfying a given predicate.
     *
     * If no predicate is provided, all the elements are flattened.
     *
     * Regardless of the category of the underlying `Sequence`,
     * `flattened_view` is only a @ref ForwardSequence.
     */
    template <typename Sequence, typename Predicate = always<true_>>
    struct flattened_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FLATTENED_VIEW_HPP
