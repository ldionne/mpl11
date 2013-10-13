/*!
 * @file
 * Forward declares `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_ALGORITHM_IS_EMPTY_FWD_HPP
#define BOOST_MPL11_ALGORITHM_IS_EMPTY_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct is_empty; }

    /*!
     * @ingroup algorithms
     * Returns whether a @ref ForwardSequence is empty.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `equal_to<begin<Sequence>::type, end<Sequence>::type>`.
     *
     *
     * @warning
     * This algorithm replaces the `mpl::empty` intrinsic from the
     * original MPL.
     */
    template <typename Sequence>
    struct is_empty
        : dispatch<tag::is_empty, Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_IS_EMPTY_FWD_HPP
