/*!
 * @file
 * Forward declares `boost::mpl11::Iterable`.
 */

#ifndef BOOST_MPL11_FWD_ITERABLE_HPP
#define BOOST_MPL11_FWD_ITERABLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup iterable_intrinsics Iterable intrinsics
     * @ingroup intrinsics
     *
     * Intrinsics forming the essential interface of `Iterable`s.
     */

    /*!
     * @ingroup mixins
     *
     * Mixin for types that can be traversed.
     *
     *
     * @note
     * The order of traversal is not necessarily meaningful.
     *
     * @todo Document this concept properly.
     */
    struct Iterable BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERABLE_HPP
