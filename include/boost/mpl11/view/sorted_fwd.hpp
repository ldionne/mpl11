/*!
 * @file
 * Forward declares `boost::mpl11::view::sorted`.
 */

#ifndef BOOST_MPL11_VIEW_SORTED_FWD_HPP
#define BOOST_MPL11_VIEW_SORTED_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/functional/quote_fwd.hpp>
#include <boost/mpl11/operator/less_fwd.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View onto the elements of a sequence sorted according to the
     * ordering relation `Predicate`.
     *
     * If left unspecified, `Predicate` is equivalent to `less<_1, _2>`.
     *
     * Regardless of the category of the underlying `Sequence`, `sorted` is
     * only a @ref ForwardSequence.
     */
    template <typename Sequence, typename Predicate = quote<less>>
    struct sorted BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_SORTED_FWD_HPP
