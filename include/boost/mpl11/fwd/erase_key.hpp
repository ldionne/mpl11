/*!
 * @file
 * Forward declares `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_FWD_ERASE_KEY_HPP
#define BOOST_MPL11_FWD_ERASE_KEY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns an @ref AssociativeSequence with the elements associated to
     * a given key removed from it.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            identity<
                indexed_view<
                    filtered_view<
                        Sequence,
                        not_equal_to<Key, key_of<Sequence, _1>>
                    >,
                    lambda<key_of<Sequence, _1>>::type,
                    lambda<value_of<Sequence, _1>>::type
                >
            >
       @endcode
     */
    template <typename Sequence, typename Key>
    struct erase_key;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ERASE_KEY_HPP
