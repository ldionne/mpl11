/*!
 * @file
 * Forward declares `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_FWD_PUSH_FRONT_HPP
#define BOOST_MPL11_FWD_PUSH_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct push_front; }

    /*!
     * @ingroup algorithms
     * Prepends an element at the beginning of a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<joined_view<single_view<Element>, Sequence>>`.
     */
    template <typename Sequence, typename Element>
    struct push_front
        : dispatch<tag::push_front, Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PUSH_FRONT_HPP