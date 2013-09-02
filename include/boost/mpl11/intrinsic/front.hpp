/*!
 * @file
 * Defines `boost::mpl11::intrinsic::front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the first element in a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `deref<begin<Sequence>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and
     * a compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct front
        : dispatch<tag::front, Sequence>
    { };
} // end namespace intrinsic

namespace front_detail {
    template <typename Sequence>
    struct assert_nonempty {
        static_assert(!intrinsic::is_empty<Sequence>::type::value,
        "Attempt to use `front` on an empty sequence.");
    };
} // end namespace front_detail

template <typename Sequence>
struct dispatch<detail::default_<tag::front>, Sequence>
    : front_detail::assert_nonempty<Sequence>,
      intrinsic::deref<typename intrinsic::begin<Sequence>::type>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_FRONT_HPP
