/*!
 * @file
 * Defines `boost::mpl11::detail::std_index_sequence`.
 */

#ifndef BOOST_MPL11_DETAIL_STD_INDEX_SEQUENCE_HPP
#define BOOST_MPL11_DETAIL_STD_INDEX_SEQUENCE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * A simple sequence of integers.
     */
    template <std_size_t ...I>
    struct std_index_sequence;

    namespace index_sequence_detail {
        template <typename L, typename R>
        struct concat;

        template <std_size_t ...I, std_size_t ...J>
        struct concat<std_index_sequence<I...>, std_index_sequence<J...>> {
            using type = std_index_sequence<I..., (sizeof...(I) + J)...>;
        };
    } // end namespace index_sequence_detail

    /*!
     * @ingroup details
     *
     * Create an `std_index_sequence` with indices from `0` to `n`.
     */
    template <std_size_t n>
    struct make_std_index_sequence {
        using type = typename index_sequence_detail::concat<
            typename make_std_index_sequence<n / 2>::type,
            typename make_std_index_sequence<n - n / 2>::type
        >::type;
    };

    template <>
    struct make_std_index_sequence<0> {
        using type = std_index_sequence<>;
    };

    template <>
    struct make_std_index_sequence<1> {
        using type = std_index_sequence<0>;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STD_INDEX_SEQUENCE_HPP
