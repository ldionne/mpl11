/*!
 * @file
 * Defines `boost::mpl11::pop_back`.
 */

#ifndef BOOST_MPL11_POP_BACK_HPP
#define BOOST_MPL11_POP_BACK_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/erase.hpp>
#include <boost/mpl11/is_empty.hpp>


namespace boost { namespace mpl11 {
namespace pop_back_detail {
    template <typename Sequence>
    struct pop_back_impl {
        static_assert(!is_empty<Sequence>::value,
        "Attempt to use `pop_back` on an empty sequence.");

        using type = typename erase<
            Sequence, typename end<Sequence>::type
        >::type;
    };
} // end namespace pop_back_detail

namespace tag { struct pop_back; }

/*!
 * Removes the element at the end of a sequence.
 *
 * The default implementation is equivalent to
 * `erase<Sequence, end<Sequence>::type>` if `is_empty<Sequence>::value` is
 * `false`, and a compile-time assertion is triggered otherwise.
 *
 * @warning
 * Differences from the original MPL:
 * - A compile-time assertion is triggered if the sequence is empty.
 */
template <typename Sequence>
struct pop_back
    : detail::tag_dispatched<tag::pop_back, Sequence>::template
      with_default<pop_back_detail::pop_back_impl<_2>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_POP_BACK_HPP
