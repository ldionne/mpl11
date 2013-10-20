/*!
 * @file
 * Forward declares `boost::mpl11::joined_view`.
 */

#ifndef BOOST_MPL11_FWD_JOINED_VIEW_HPP
#define BOOST_MPL11_FWD_JOINED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * A view into the sequence of elements formed by concatenating two
     * or more sequences.
     *
     * Regardless of the category of the underlying sequences, `joined_view`
     * is only a @ref ForwardSequence.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct joined_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_JOINED_VIEW_HPP
