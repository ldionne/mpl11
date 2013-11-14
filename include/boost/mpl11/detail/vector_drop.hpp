/*!
 * @file
 * Defines `boost::mpl11::detail::vector_drop`.
 */

#ifndef BOOST_MPL11_DETAIL_VECTOR_DROP_HPP
#define BOOST_MPL11_DETAIL_VECTOR_DROP_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns a `mpl11::vector` containing all the elements in
     * the range [`Index`, `sizeof...(An)`) in O(1).
     */
    template <typename Vector, unsigned long long Index>
    struct vector_drop;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/detail/vector_fill.hpp>
#include <boost/mpl11/fwd/vector.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace vector_drop_detail {
        template <typename IgnoreHead>
        struct drop_impl;

        template <typename ...IgnoreHead>
        struct drop_impl<vector<IgnoreHead...>> {
            template <typename ...Tail>
            static vector<Tail...> apply(IgnoreHead..., no_decay<Tail>*...);
        };
    } // end namespace vector_drop_detail

    template <typename ...An, unsigned long long Index>
    struct vector_drop<vector<An...>, Index> {
        static_assert(Index <= sizeof...(An),
        "Dropping too many elements from a `vector`.");

        using type = decltype(
            vector_drop_detail::drop_impl<
                typename vector_fill<Index, void*>::type
            >::apply((no_decay<An>*)nullptr...)
        );
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VECTOR_DROP_HPP
