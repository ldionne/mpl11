/*!
 * @file
 * Defines `boost::mpl11::intrinsic::erase_key`.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP

#include <boost/mpl11/algorithm/remove_if.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
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
            remove_if<
                Sequence,
                equal_to<Key, key_of<Sequence, _1>>
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
        : detail::tag_dispatched<tag::erase_key, Sequence, Key>
    { };
} // end namespace intrinsic

template <typename Sequence, typename Key>
struct dispatch<detail::default_<tag::erase_key>, Sequence, Key>
    : algorithm::remove_if<
        Sequence,
        intrinsic::equal_to<Key, intrinsic::key_of<Sequence, _1>>
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
