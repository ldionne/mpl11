/*!
 * @file
 * Forward declares `boost::mpl11::has_key`.
 */

#ifndef BOOST_MPL11_FWD_HAS_KEY_HPP
#define BOOST_MPL11_FWD_HAS_KEY_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct has_key; }

    /*!
     * @ingroup algorithms
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HAS_KEY_HPP
