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
     * Inserts a range of elements at an arbitrary position in a
     * @ref ForwardSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * @code
     *     identity<
     *         joined_view<
     *             iterator_range<begin<Sequence>::type, Position>,
     *             Range,
     *             iterator_range<Position, end<Sequence>::type>
     *         >
     *      >
     * @endcode
     */
    template <typename Sequence, typename Position, typename Range>
    struct insert_range BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Range>);

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
