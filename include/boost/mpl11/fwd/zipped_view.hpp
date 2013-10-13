/*!
 * @file
 * Forward declares `boost::mpl11::zipped_view`.
 */

#ifndef BOOST_MPL11_FWD_ZIPPED_VIEW_HPP
#define BOOST_MPL11_FWD_ZIPPED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View over the elements of several zipped sequences.
     *
     * Specifically, each element of `zipped_view` is a sequence containing
     * the elements of each zipped sequence at that position.
     *
     * The number of elements in `zipped_view` is equal to the number of
     * elements of the smallest zipped sequence.
     *
     * Regardless of the category of the underlying sequences, `zipped_view`
     * is only a @ref ForwardSequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - The sequences to zip are specified using variadic template parameters
     *   instead of being provided as a sequence of sequences.
     * - The type of the sequence used to pass the arguments to `zipped_view`
     *   does not affect the type of its elements, since the arguments are
     *   not provided in a sequence anymore.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct zipped_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ZIPPED_VIEW_HPP
