/*!
 * @file
 * Forward declares `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_BACK_FWD_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_BACK_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct push_back; }

    /*!
     * @ingroup intrinsics
     *
     * Inserts an element at the end of a @ref BackExtensibleSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `insert<Sequence, end<Sequence>::type, Element>`.
     */
    template <typename Sequence, typename Element>
    struct push_back
        : dispatch<tag::push_back, Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_PUSH_BACK_FWD_HPP
