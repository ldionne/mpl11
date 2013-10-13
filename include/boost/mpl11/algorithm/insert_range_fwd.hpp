/*!
 * @file
 * Defines `boost::mpl11::insert_range`.
 */

#ifndef BOOST_MPL11_ALGORITHM_INSERT_RANGE_HPP
#define BOOST_MPL11_ALGORITHM_INSERT_RANGE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct insert_range : dispatch<insert_range> { }; }

    /*!
     * @ingroup algorithms
     * Overloaded algorithm for inserting a range of elements in a sequence.
     */
    template <typename, typename, typename = detail::optional>
    struct insert_range;

    /*!
     * @ingroup algorithms
     * Inserts a range of elements at an arbitrary position in a
     * @ref ForwardSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * @code
     *     identity<
     *         view::joined<
     *             view::bounded_by<begin<Sequence>::type, Position>,
     *             Range,
     *             view::bounded_by<Position, end<Sequence>::type>
     *         >
     *      >
     * @endcode
     */
    template <typename Sequence, typename Position, typename Range>
    struct insert_range BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Range>)
        : dispatch<tag::insert_range, Sequence, Position, Range>
    { };

    /*!
     * @ingroup algorithms
     * Inserts a range of elements in an @ref AssociativeSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Let `Filtered` be identical to
     * @code
     *     foldl<
     *         Range,
     *         Sequence,
     *         erase_key<_1, key_of<Range, _2>>
     *     >::type
     * @endcode
     *
     * Then, `insert_range` is equivalent to
     * `identity<view::joined<Range, Filtered>>`.
     */
    template <typename Sequence, typename Range>
    struct insert_range<Sequence, Range>
        : dispatch<tag::insert_range, Sequence, Range>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_INSERT_RANGE_HPP
