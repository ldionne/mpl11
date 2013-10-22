/*!
 * @file
 * Forward declares `boost::mpl11::view::onto_iterators`.
 */

#ifndef BOOST_MPL11_VIEW_ONTO_ITERATORS_FWD_HPP
#define BOOST_MPL11_VIEW_ONTO_ITERATORS_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View onto the iterators of a sequence.
     *
     * The category of `onto_iterators` depends on the category of the
     * underlying `Sequence`.
     */
    template <typename Sequence>
    struct onto_iterators BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_ONTO_ITERATORS_FWD_HPP
