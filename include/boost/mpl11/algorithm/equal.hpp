/*!
 * @file
 * Defines `boost::mpl11::algorithm::equal`.
 */

#ifndef BOOST_MPL11_ALGORITHM_EQUAL_HPP
#define BOOST_MPL11_ALGORITHM_EQUAL_HPP

#include <boost/mpl11/algorithm/all_of.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/unpack_args.hpp>
#include <boost/mpl11/view/zipped.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for comparing two sequences element-by-element.
     */
    template <typename Sequence1,
              typename Sequence2,
              typename Predicate = detail::optional>
    struct equal;

    /*!
     * @ingroup algorithm
     *
     * Returns whether two sequences are identical when compared
     * element-by-element with a custom `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * If `size<Sequence1>::type::value == size<Sequence2>::type::value`,
     * equivalent to
       @code
            all_of<
                zip_view<Sequence1, Sequence2>,
                unpack_args<Predicate>
            >
       @endcode
     * Otherwise, it is equivalent to `identity<false_>`.
     */
    template <typename Sequence1, typename Sequence2, typename Predicate>
    struct equal BOOST_MPL11_DOXYGEN_ONLY(<Sequence1, Sequence2, Predicate>)
        : detail::tag_dispatched<tag::equal, Sequence1, Sequence2, Predicate>
    { };

    /*!
     * @ingroup algorithm
     *
     * Returns whether two sequences are identical when compared
     * element-by-element.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `equal<Sequence1, Sequence2, equal_to<_1, _2>>`.
     */
    template <typename Sequence1, typename Sequence2>
    struct equal<Sequence1, Sequence2>
        : detail::tag_dispatched<tag::equal, Sequence1, Sequence2>
    { };
} // end namespace algorithm

template <typename Sequence1, typename Sequence2>
struct dispatch<detail::default_<tag::equal>, Sequence1, Sequence2>
    : algorithm::equal<Sequence1, Sequence2, quote<intrinsic::equal_to>>
{ };

template <typename Sequence1, typename Sequence2, typename Predicate>
struct dispatch<detail::default_<tag::equal>, Sequence1, Sequence2, Predicate>
    : intrinsic::and_<
        intrinsic::equal_to<
            typename intrinsic::size<Sequence1>::type,
            typename intrinsic::size<Sequence2>::type
        >,
        algorithm::all_of<
            view::zipped<Sequence1, Sequence2>,
            unpack_args<Predicate>
        >
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_EQUAL_HPP
