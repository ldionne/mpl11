/*!
 * @file
 * Forward declares `boost::mpl11::view::onto_values`.
 */

#ifndef BOOST_MPL11_VIEW_ONTO_VALUES_FWD_HPP
#define BOOST_MPL11_VIEW_ONTO_VALUES_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View onto the values of an @ref AssociativeSequence.
     *
     * The category of `onto_values` depends on the category of the
     * underlying `Sequence`.
     */
    template <typename Sequence>
    struct onto_values BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_ONTO_VALUES_FWD_HPP
