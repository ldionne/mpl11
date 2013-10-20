/*!
 * @file
 * Forward declares `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_FWD_PUSH_BACK_HPP
#define BOOST_MPL11_FWD_PUSH_BACK_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct push_back; }

    /*!
     * @ingroup algorithms
     * Appends an element at the end of a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<joined_view<Sequence, single_view<Element>>>`.
     */
    template <typename Sequence, typename Element>
    struct push_back
        : dispatch<tag::push_back, Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PUSH_BACK_HPP
