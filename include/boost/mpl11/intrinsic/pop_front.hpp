/*!
 * @file
 * Defines `boost::mpl11::pop_front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_POP_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Removes the element at the beginning of a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `erase<Sequence, begin<Sequence>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and a
     * compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct pop_front
        : dispatch<tag::pop_front, Sequence>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/pop_front.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_POP_FRONT_HPP
