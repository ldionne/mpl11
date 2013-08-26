/*!
 * @file
 * Defines `boost::mpl11::back`.
 */

#ifndef BOOST_MPL11_BACK_HPP
#define BOOST_MPL11_BACK_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/prior.hpp>


namespace boost { namespace mpl11 {
namespace back_detail {
    template <typename Sequence>
    struct back_impl {
        static_assert(!is_empty<Sequence>::value,
        "Attempt to use `back` on an empty sequence.");

        using type = typename deref<
            typename prior<typename end<Sequence>::type>::type
        >::type;
    };
} // end namespace back_detail

namespace tag { struct back; }

/*!
 * Returns the last element in a sequence if there is such an element, and
 * triggers a compile-time assertion otherwise.
 *
 * The default implementation is equivalent to
 * `deref<prior<end<Sequence>::type>::type>` if `is_empty<Sequence>::value`
 * is `false`, and a compile-time assertion is triggered otherwise.
 *
 * @warning
 * Differences from the original MPL:
 * - A compile-time assertion is triggered if the sequence is empty.
 */
template <typename Sequence>
struct back
    : detail::tag_dispatched<tag::back, Sequence>::template
      with_default<back_detail::back_impl<_2>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_HPP
