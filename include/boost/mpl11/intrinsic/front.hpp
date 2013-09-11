/*!
 * @file
 * Defines `boost::mpl11::front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
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
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/front.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_FRONT_HPP
