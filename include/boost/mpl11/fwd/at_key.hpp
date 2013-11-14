/*!
 * @file
 * Forward declares `boost::mpl11::at_key`.
 */

#ifndef BOOST_MPL11_FWD_AT_KEY_HPP
#define BOOST_MPL11_FWD_AT_KEY_HPP

#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the value associated with the given `Key` in an
     * `AssociativeSequence`.
     *
     * If the sequence does not contain a key `Key` and a `Default` is
     * provided, the `Default` is returned. Otherwise, a compile-time
     * assertion is triggered.
     *
     *
     * @todo
     * Consider returning a `Logical` from `at_key<%Sequence, Key>`.
     * Something like a `Maybe` would be neat.
     */
    template <
        typename Sequence,
        typename Key,
        typename Default = detail::optional
    >
    struct at_key;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AT_KEY_HPP
