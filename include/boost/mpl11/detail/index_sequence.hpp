/*!
 * @file
 * Defines `boost::mpl11::detail::index_sequence`.
 */

#ifndef BOOST_MPL11_DETAIL_INDEX_SEQUENCE_HPP
#define BOOST_MPL11_DETAIL_INDEX_SEQUENCE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>

#include <boost/mpl11/fwd/join.hpp>


namespace boost { namespace mpl11 {
namespace detail {
    /*!
     * @ingroup details
     *
     * A simple sequence of integers.
     */
    template <std_size_t ...I>
    struct index_sequence;

    /*!
     * @ingroup details
     *
     * Create an `index_sequence` with indices from `0` to `N`.
     */
    template <std_size_t N>
    struct make_index_sequence
        : join<
            typename make_index_sequence<N / 2>::type,
            typename make_index_sequence<N - N / 2>::type
        >
    { };

    template <>
    struct make_index_sequence<0> {
        using type = index_sequence<>;
    };

    template <>
    struct make_index_sequence<1> {
        using type = index_sequence<0>;
    };
} // end namespace detail

// Avoid creating a new template.
template <detail::std_size_t ...I, detail::std_size_t ...J>
struct join<detail::index_sequence<I...>, detail::index_sequence<J...>> {
    using type = detail::index_sequence<I..., (sizeof...(I) + J)...>;
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_INDEX_SEQUENCE_HPP
