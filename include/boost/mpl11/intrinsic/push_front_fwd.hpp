/*!
 * @file
 * Forward declares `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_FRONT_FWD_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_FRONT_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct push_front; }

    /*!
     * @ingroup intrinsics
     *
     * Inserts an element at the beginning of a @ref FrontExtensibleSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `insert<Sequence, begin<Sequence>::type, Element>`.
     */
    template <typename Sequence, typename Element>
    struct push_front
        : dispatch<tag::push_front, Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_PUSH_FRONT_FWD_HPP
