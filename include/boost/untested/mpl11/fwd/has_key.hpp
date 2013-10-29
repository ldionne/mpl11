/*!
 * @file
 * Forward declares `boost::mpl11::has_key`.
 */

#ifndef BOOST_MPL11_FWD_HAS_KEY_HPP
#define BOOST_MPL11_FWD_HAS_KEY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * @todo No default implementation is provided.
     * Returns whether an @ref AssociativeSequence contains one or more
     * elements with key `Key`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            not_equal_to<
                find_if<
                    Sequence,
                    equal_to<Key, key_of<Sequence, _1>>
                >::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence, typename Key>
    struct has_key;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HAS_KEY_HPP
