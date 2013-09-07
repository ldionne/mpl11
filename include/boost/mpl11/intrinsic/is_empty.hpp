/*!
 * @file
 * Defines `boost::mpl11::intrinsic::is_empty`.
 */

#ifndef BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP
#define BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
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
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/is_empty.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP
