/*!
 * @file
 * Defines `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_ERASE_KEY_HPP
#define BOOST_MPL11_ERASE_KEY_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/remove_if.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace erase_key_detail {
    template <typename Sequence, typename Key>
    struct erase_key_impl
        : remove_if<
            Sequence, is_same<Key, key_of<Sequence, _1>>
        >
    { };
} // end namespace erase_key_detail

/*!
 * Erases elements associated with a given key in an associative sequence.
 *
 * The default implementation is equivalent to
   @code
        remove_if<
            AssociativeSequence,
            is_same<Key, key_of<AssociativeSequence, _1>>
        >
   @endcode
 *
 * @warning
 * Differences from the original MPL:
 * - A default implementation is provided.
 */
template <typename AssociativeSequence, typename Key>
struct erase_key
    : detail::tag_dispatched<tag::erase_key, AssociativeSequence, Key>
      ::template with_default<erase_key_detail::erase_key_impl<_2, _3>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_KEY_HPP
