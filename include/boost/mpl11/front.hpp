/*!
 * @file
 * Defines `boost::mpl11::front`.
 */

#ifndef BOOST_MPL11_FRONT_HPP
#define BOOST_MPL11_FRONT_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace front_detail {
    template <typename Sequence>
    struct front_impl {
        static_assert(!is_empty<Sequence>::value,
        "Attempt to use `front` on an empty sequence.");

        using type = typename deref<typename begin<Sequence>::type>::type;
    };
}

/*!
 * Returns the first element in a sequence.
 *
 * The default implementation is equivalent to `deref<begin<Sequence>::type>`
 * if `is_empty<Sequence>::value` is `false`, and a compile-time assertion
 * is triggered otherwise.
 *
 * @warning
 * Differences from the original MPL:
 * - A compile-time assertion is triggered if the sequence is empty.
 */
template <typename Sequence>
struct front
    : detail::tag_dispatched<tag::front, Sequence>::template
      with_default<front_detail::front_impl<_1>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FRONT_HPP
