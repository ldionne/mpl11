/*!
 * @file
 * Forward declares `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_INTRINSIC_IS_EMPTY_FWD_HPP
#define BOOST_MPL11_INTRINSIC_IS_EMPTY_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct is_empty; }

    /*!
     * @ingroup intrinsics
     *
     * Returns whether a sequence is empty.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `equal_to<begin<Sequence>::type, end<Sequence>::type>`.
     *
     *
     * @warning
     * This intrinsic replaces `mpl::empty` from the original MPL.
     */
    template <typename Sequence>
    struct is_empty
        : dispatch<tag::is_empty, Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_IS_EMPTY_FWD_HPP
