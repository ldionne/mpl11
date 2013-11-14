/*!
 * @file
 * Defines `boost::mpl11::detail::vector_concat`.
 */

#ifndef BOOST_MPL11_DETAIL_VECTOR_CONCAT_HPP
#define BOOST_MPL11_DETAIL_VECTOR_CONCAT_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Concatenate two or more `mpl11::vector`s.
     */
    template <typename Vector1, typename Vector2, typename ...VectorN>
    struct vector_concat;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/fwd/vector.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Vector1, typename Vector2, typename ...VectorN>
    struct vector_concat
        : vector_concat<
            Vector1, typename vector_concat<Vector2, VectorN...>::type
        >
    { };

    template <typename ...An, typename ...Bn>
    struct vector_concat<vector<An...>, vector<Bn...>> {
        using type = vector<An..., Bn...>;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VECTOR_CONCAT_HPP
