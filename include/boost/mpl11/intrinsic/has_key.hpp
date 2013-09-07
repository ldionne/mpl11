/*!
 * @file
 * Defines `boost::mpl11::intrinsic::has_key`.
 */

#ifndef BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
#define BOOST_MPL11_INTRINSIC_HAS_KEY_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns whether an `AssociativeSequence` contains an element
     * with key `Key`.
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
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A default implementation is provided.
     */
    template <typename Sequence, typename Key>
    struct has_key
        : dispatch<tag::has_key, Sequence, Key>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/has_key.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
