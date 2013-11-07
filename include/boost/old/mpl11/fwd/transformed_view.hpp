/*!
 * @file
 * Forward declares `boost::mpl11::transformed_view`.
 */

#ifndef BOOST_MPL11_FWD_TRANSFORMED_VIEW_HPP
#define BOOST_MPL11_FWD_TRANSFORMED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View over a `Sequence`'s elements transformed by the
     * application of `F`.
     *
     * The category of `transformed_view` depends on the category of
     * the underlying `Sequence`.
     */
    template <typename Sequence, typename F>
    struct transformed_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TRANSFORMED_VIEW_HPP
