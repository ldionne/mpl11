/*!
 * @file
 * Defines `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
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

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/push_front.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
