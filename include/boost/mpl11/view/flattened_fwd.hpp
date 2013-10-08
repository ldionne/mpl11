/*!
 * @file
 * Forward declares `boost::mpl11::view::flattened`.
 */

#ifndef BOOST_MPL11_VIEW_FLATTENED_FWD_HPP
#define BOOST_MPL11_VIEW_FLATTENED_FWD_HPP

#include <boost/mpl11/bool_fwd.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/functional/always_fwd.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View of a sequence as the concatenation of all its elements
     * (seen as sequences themselves) satisfying a given predicate.
     *
     * If no predicate is provided, all the elements are flattened.
     *
     * Regardless of the category of the underlying `Sequence`,
     * `flattened` is only a @ref ForwardSequence.
     */
    template <typename Sequence, typename Predicate = always<true_>>
    struct flattened BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_FLATTENED_FWD_HPP
