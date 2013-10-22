/*!
 * @file
 * Forward declares `boost::mpl11::view::zipped`.
 */

#ifndef BOOST_MPL11_VIEW_ZIPPED_FWD_HPP
#define BOOST_MPL11_VIEW_ZIPPED_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View over the elements of several zipped sequences.
     *
     * Specifically, each element of `zipped` is a sequence containing
     * the elements of each zipped sequence at that position.
     *
     * The number of elements in `zipped` is equal to the number of
     * elements of the smallest zipped sequence.
     *
     * Regardless of the category of the underlying sequences, `zipped`
     * is only a @ref ForwardSequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - The sequences to zip are specified using variadic template parameters
     *   instead of being provided as a sequence of sequences.
     * - The type of the sequence used to pass the arguments to `zipped`
     *   does not affect the type of its elements, since the arguments are
     *   not provided in a sequence anymore.
     */
    template <typename Sequence1, typename Sequence2, typename ...SequenceN>
    struct zipped BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_ZIPPED_FWD_HPP
