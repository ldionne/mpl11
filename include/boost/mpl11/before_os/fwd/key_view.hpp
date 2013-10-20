/*!
 * @file
 * Forward declares `boost::mpl11::key_view`.
 */

#ifndef BOOST_MPL11_FWD_KEY_VIEW_HPP
#define BOOST_MPL11_FWD_KEY_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View onto the keys of an @ref AssociativeSequence.
     *
     * The category of `key_view` depends on the category of the
     * underlying `Sequence`.
     */
    template <typename Sequence>
    struct key_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_KEY_VIEW_HPP
