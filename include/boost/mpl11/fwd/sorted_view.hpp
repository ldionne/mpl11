/*!
 * @file
 * Forward declares `boost::mpl11::sorted_view`.
 */

#ifndef BOOST_MPL11_FWD_SORTED_VIEW_HPP
#define BOOST_MPL11_FWD_SORTED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View onto the elements of a sequence sorted according to the
     * ordering relation `Predicate`.
     *
     * If left unspecified, `Predicate` is equivalent to `less<_1, _2>`.
     *
     * Regardless of the category of the underlying `Sequence`,
     * `sorted_view` is only a @ref ForwardSequence.
     */
    template <typename Sequence, typename Predicate = quote<less>>
    struct sorted_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SORTED_VIEW_HPP
