/*!
 * @file
 * Forward declares `boost::mpl11::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup RandomAccessSequence RandomAccessSequence
     *
     * Collection of types providing efficient access to elements
     * anywhere in the sequence.
     *
     *
     * ### Refines
     * `ForwardSequence`
     *
     * ### Methods
     * `at`, `slice`
     *
     * ### Minimal complete definition
     * `at` and `slice`.
     */
    template <typename Tag>
    struct RandomAccessSequence;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
