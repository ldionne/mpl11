/*!
 * @file
 * Defines `boost::mpl11::eq`.
 */

#ifndef BOOST_MPL11_EQ_HPP
#define BOOST_MPL11_EQ_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 {
namespace eq_detail {
template <typename Category1, typename T,
          typename Category2, typename U>
struct eq_impl
    : is_same<T, U>
{ };

template <typename Sequence1, typename Sequence2>
struct eq_impl<tag::forward_sequence_at_least, Sequence1,
               tag::forward_sequence_at_least, Sequence2>
    : equal<Sequence1, Sequence2>
{ };

template <typename I1, typename I2>
struct eq_impl<tag::integral_c, I1, tag::integral_c, I2>
    : bool_<I1::type::value == I2::type::value>
{ };

template <typename Sequence1, typename Sequence2>
struct eq_impl<tag::associative, Sequence1, tag::associative, Sequence2>
    : and_<
        is_permutation<key_view<Sequence1>, key_view<Sequence2>>,
        all_of<
            key_view<Sequence1>,
            eq<at<Sequence1, _1>, at<Sequence1, _1>>
        >
    >
{ };

template <typename Sequence1, typename Category2, typename Sequence2>
struct eq_impl<tag::associative, Sequence1, Category2, Sequence2> {
    static_assert(detail::always_false<
        tag::associative, Sequence1, Category2, Sequence2
    >::value,
    "Attempt to use the default implementation of `eq` with an "
    "associative sequence and another type of sequence.");

    struct type;
};

template <typename Category1, typename Sequence1, typename Sequence2>
struct eq_impl<Category1, Sequence1, tag::associative, Sequence2>
    : eq_impl<tag::associative, Sequence2, Category1, Sequence1>
{ };
} // end namespace eq_detail

namespace tag { struct eq; }

/*!
 * equivalent to operator==
 */
template <typename T, typename U>
struct eq
    : detail::tag_dispatched<tag::eq, T, U>
      ::template with_default<
        eq_detail::eq_impl<
            traversal_category_of<_2>, _2,
            traversal_category_of<_3>, _3
        >
      >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQ_HPP
