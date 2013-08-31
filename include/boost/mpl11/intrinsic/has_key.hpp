/*!
 * @file
 * Defines `boost::mpl11::intrinsic::has_key`.
 */

#ifndef BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
#define BOOST_MPL11_INTRINSIC_HAS_KEY_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/intrinsic/not_equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace has_key_detail {
    template <typename Sequence, typename Key>
    struct has_key_impl
        : intrinsic::not_equal_to<
            typename algorithm::find_if<
                Sequence,
                intrinsic::equal_to<Key, intrinsic::key_of<Sequence, _1>>
            >::type,
            typename intrinsic::end<Sequence>::type
        >
    { };
} // end namespace has_key_detail

namespace intrinsic {
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
        : detail::tag_dispatched<tag::has_key, Sequence, Key>::template
          with_default<
            lazy_always<
                has_key_detail::has_key_impl<Sequence, Key>
            >
          >
    { };
} // end namespace intrinsic
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
