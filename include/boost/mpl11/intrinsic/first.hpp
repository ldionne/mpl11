/*!
 * @file
 * Defines `boost::mpl11::intrinsic::first`.
 */

#ifndef BOOST_MPL11_INTRINSIC_FIRST_HPP
#define BOOST_MPL11_INTRINSIC_FIRST_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the first element of a pair.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     * - The operation uses standard tag dispatching.
     */
    template <typename Pair>
    struct first
        : detail::tag_dispatched<tag::first, Pair>::template
          with_default<>
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_FIRST_HPP
