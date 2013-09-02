/*!
 * @file
 * Defines `boost::mpl11::intrinsic::has_key`.
 */

#ifndef BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
#define BOOST_MPL11_INTRINSIC_HAS_KEY_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/intrinsic/not_equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
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
        : dispatch<tag::has_key, Sequence, Key>
    { };
} // end namespace intrinsic

template <typename Sequence, typename Key>
struct dispatch<detail::default_<tag::has_key>, Sequence, Key>
    : intrinsic::not_equal_to<
        typename algorithm::find_if<
            Sequence,
            intrinsic::equal_to<Key, intrinsic::key_of<Sequence, _1>>
        >::type,
        typename intrinsic::end<Sequence>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_HAS_KEY_HPP
