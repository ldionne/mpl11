/*!
 * @file
 * Defines `boost::mpl11::intrinsic::pop_back`.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_BACK_HPP
#define BOOST_MPL11_INTRINSIC_POP_BACK_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace pop_back_detail {
    template <typename Sequence>
    struct pop_back_impl {
        static_assert(!intrinsic::is_empty<Sequence>::value,
        "Attempt to use `pop_back` on an empty sequence.");

        using type = typename intrinsic::erase<
            Sequence,
            typename intrinsic::end<Sequence>::type
        >::type;
    };
} // end namespace pop_back_detail

namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Removes the element at the end of a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `erase<Sequence, end<Sequence>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and a
     * compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct pop_back
        : detail::tag_dispatched<tag::pop_back, Sequence>::template
          with_default<
            lazy_always<
                pop_back_detail::pop_back_impl<Sequence>
            >
          >
    { };
} // end namespace intrinsic
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_POP_BACK_HPP
