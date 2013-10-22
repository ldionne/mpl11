/*!
 * @file
 * Forward declares `boost::mpl11::pop_front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_FRONT_FWD_HPP
#define BOOST_MPL11_INTRINSIC_POP_FRONT_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct pop_front; }

    /*!
     * @ingroup intrinsics
     *
     * Removes the element at the beginning of a @ref FrontExtensibleSequence.
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

#endif // !BOOST_MPL11_INTRINSIC_POP_FRONT_FWD_HPP
