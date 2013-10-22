/*!
 * @file
 * Forward declares `boost::mpl11::size`.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_FWD_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct size; }

    /*!
     * @ingroup intrinsics
     *
     * Returns the number of elements contained in a sequence.
     *
     * The size of a sequence is a non-negative @ref IntegralConstant.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `distance<begin<Sequence>::type, end<Sequence>::type>`.
     */
    template <typename Sequence>
    struct size
        : dispatch<tag::size, Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_SIZE_FWD_HPP
