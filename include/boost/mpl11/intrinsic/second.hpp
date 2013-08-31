/*!
 * @file
 * Defines `boost::mpl11::intrinsic::second`.
 */

#ifndef BOOST_MPL11_INTRINSIC_SECOND_HPP
#define BOOST_MPL11_INTRINSIC_SECOND_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the second element of a pair.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     * - The operation uses standard tag dispatching.
     */
    template <typename Pair>
    struct second
        : detail::tag_dispatched<tag::second, Pair>::template
          with_default<>
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_SECOND_HPP
