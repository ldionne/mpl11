/*!
 * @file
 * Defines `boost::mpl11::intrinsic::erase_key`.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Erases elements associated with a given key in
     * an `AssociativeSequence`.
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
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/erase_key.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
