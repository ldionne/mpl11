/*!
 * @file
 * Forward declares `boost::mpl11::view::joined`.
 */

#ifndef BOOST_MPL11_VIEW_JOINED_FWD_HPP
#define BOOST_MPL11_VIEW_JOINED_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * A view into the sequence of elements formed by concatenating two
     * or more sequences.
     *
     * Regardless of the category of the underlying sequences, `joined`
     * is only a @ref ForwardSequence.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct joined BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_JOINED_FWD_HPP
