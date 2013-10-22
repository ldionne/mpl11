/*!
 * @file
 * Forward declares `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_KEY_FWD_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_KEY_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct erase_key; }

    /*!
     * @ingroup intrinsics
     *
     * Erases elements associated with a given key in
     * an @ref AssociativeSequence.
     *
     *
     * ### Semantics and default implementation
     * Equivalent to
       @code
            copy<
                filtered<
                    Sequence,
                    not_equal_to<Key, key_of<Sequence, _1>>
                >,
                clear<Sequence>::type
            >
       @endcode
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A default implementation is provided.
     */
    template <typename Sequence, typename Key>
    struct erase_key
        : dispatch<tag::erase_key, Sequence, Key>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_ERASE_KEY_FWD_HPP
