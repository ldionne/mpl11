/*!
 * @file
 * Forwards declare some intrinsics and algorithms to break
 * circular dependencies.
 */

#ifndef BOOST_MPL11_DETAIL_FORWARD_DECLS_HPP
#define BOOST_MPL11_DETAIL_FORWARD_DECLS_HPP

#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Overloaded intrinsic for inserting elements in a sequence.
     */
    template <typename Sequence,
              typename Position,
              typename Element = detail::optional>
    struct insert;

    template <typename Sequence>
    struct clear;
} // end namespace intrinsic

namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for copying elements from a sequence to another.
     */
    template <typename From, typename To, typename Insert = detail::optional>
    struct copy;
} // end namespace algorithm
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_FORWARD_DECLS_HPP
