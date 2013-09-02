/*!
 * @file
 * Defines `boost::mpl11::intrinsic::back`.
 */

#ifndef BOOST_MPL11_INTRINSIC_BACK_HPP
#define BOOST_MPL11_INTRINSIC_BACK_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the last element in a sequence if there is such an element, and
     * triggers a compile-time assertion otherwise.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `deref<prior<end<Sequence>::type>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and a
     * compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct back
        : detail::tag_dispatched<tag::back, Sequence>
    { };
} // end namespace intrinsic

namespace back_detail {
    template <typename Sequence>
    struct assert_nonempty {
        static_assert(!intrinsic::is_empty<Sequence>::type::value,
        "Attempt to use `back` on an empty sequence.");
    };
} // end namespace back_detail

template <typename Sequence>
struct dispatch<detail::default_<tag::back>, Sequence>
    : back_detail::assert_nonempty<Sequence>,
      intrinsic::deref<
        typename intrinsic::prior<
            typename intrinsic::end<Sequence>::type
        >::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_BACK_HPP
