/*!
 * @file
 * Forward declares `boost::mpl11::view::transformed`.
 */

#ifndef BOOST_MPL11_VIEW_TRANSFORMED_FWD_HPP
#define BOOST_MPL11_VIEW_TRANSFORMED_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View over a `Sequence`'s elements transformed by the
     * application of `F`.
     *
     * The category of `transformed` depends on the category of
     * the underlying `Sequence`.
     */
    template <typename Sequence, typename F>
    struct transformed BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_TRANSFORMED_FWD_HPP
