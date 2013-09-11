/*!
 * @file
 * Defines `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Inserts an element at the end of a sequence.
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

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/push_back.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
