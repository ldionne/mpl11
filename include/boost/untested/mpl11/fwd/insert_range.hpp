/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_INSERT_RANGE_HPP
#define BOOST_MPL11_INSERT_RANGE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Inserts a range of elements in an @ref AssociativeSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `foldl<Range, Sequence, insert<_1, _2>>`.
     */
    template <typename Sequence, typename Range>
    struct insert_range<Sequence, Range>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_RANGE_HPP
