/*!
 * @file
 * Defines `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_EQUAL_HPP
#define BOOST_MPL11_EQUAL_HPP

#include <boost/mpl11/all_of.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/always_false.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/eq.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/unpack_args.hpp>
#include <boost/mpl11/zip_view.hpp>


namespace boost { namespace mpl11 {
namespace equal_detail {
    template <typename Sequence1, typename Sequence2, typename Predicate>
    struct equal_impl
        : and_<
            eq<size<Sequence1>, size<Sequence2>>,
            all_of<
                zip_view<Sequence1, Sequence2>,
                unpack_args<Predicate>
            >
        >
    { };
} // end namespace equal_detail

namespace tag { struct equal; }

template <typename Sequence1, typename Sequence2, typename ...Predicate>
struct equal {
    static_assert(
    detail::always_false<Sequence1, Sequence2, Predicate...>::value,
    "Too many arguments to `equal`. "
    "Usage is `equal<Sequence1, Sequence2[, Predicate]>`.");

    struct type;
};

/*!
 * Returns whether two sequences are identical when compared
 * element-by-element with a custom `Predicate`.
 *
 * If `size<Sequence1>::value == size<Sequence2>::value`, the default
 * implementation is equivalent to
   @code
        all_of<
            zip_view<Sequence1, Sequence2>,
            unpack_args<lambda<Predicate>::type>
        >
   @endcode
 * Otherwise, it is equivalent to `false_`.
 *
 * @warning
 * Differences from the original MPL:
 * - The default implementation differs but the semantics are the same.
 */
template <typename Sequence1, typename Sequence2, typename Predicate>
struct equal<Sequence1, Sequence2, Predicate>
    : detail::tag_dispatched<tag::equal, Sequence1, Sequence2, Predicate>
      ::template with_default<
        equal_detail::equal_impl<_2, _3, lambda<_4>>
      >
{ };

/*!
 * Returns whether two sequences are identical when compared
 * element-by-element.
 *
 * The default implementation is equivalent to
 * `equal<Sequence1, Sequence2, is_same<_1, _2>>`.
 */
template <typename Sequence1, typename Sequence2>
struct equal<Sequence1, Sequence2>
    : detail::tag_dispatched<tag::equal, Sequence1, Sequence2>::template
      with_default<equal<Sequence1, Sequence2, quote<is_same>>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQUAL_HPP
