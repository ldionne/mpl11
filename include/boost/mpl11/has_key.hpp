/*!
 * @file
 * Defines `boost::mpl11::has_key`.
 */

#ifndef BOOST_MPL11_HAS_KEY_HPP
#define BOOST_MPL11_HAS_KEY_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace has_key_detail {
    template <typename Sequence, typename Key>
    struct has_key_impl
        : not_<
            is_same<
                typename find_if<
                    Sequence, is_same<Key, key_of<Sequence, _1>>
                >::type,
                typename end<Sequence>::type
            >
        >
    { };
} // end namespace has_key_detail

/*!
 * Returns whether an associative sequence contains an element with key `Key`.
 *
 * The default implementation is equivalent to
   @code
        not_<
            is_same<
                find_if<
                    AssociativeSequence,
                    is_same<Key, key_of<AssociativeSequence, _1>>
                >::type,
                end<AssociativeSequence>::type
            >
        >
   @endcode
 *
 * @warning
 * Differences from the original MPL:
 * - A default implementation is provided.
 */
template <typename Sequence, typename Key>
struct has_key
    : detail::tag_dispatched<tag::has_key, Sequence, Key>::template
      with_default<has_key_detail::has_key_impl<_1, _2>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HAS_KEY_HPP
