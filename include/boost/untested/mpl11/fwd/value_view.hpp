/*!
 * @file
 * Forward declares `boost::mpl11::value_view`.
 */

#ifndef BOOST_MPL11_FWD_VALUE_VIEW_HPP
#define BOOST_MPL11_FWD_VALUE_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View onto the values of an @ref AssociativeSequence.
     *
     * The category of `value_view` depends on the category of the
     * underlying `Sequence`.
     */
    template <typename Sequence>
    struct value_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_VALUE_VIEW_HPP
