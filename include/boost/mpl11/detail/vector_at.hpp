/*!
 * @file
 * Defines `boost::mpl11::detail::vector_at`.
 */

#ifndef BOOST_MPL11_DETAIL_VECTOR_AT_HPP
#define BOOST_MPL11_DETAIL_VECTOR_AT_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns the parameter at position `N` in a `mpl11::vector` in O(1).
     */
    template <typename Vector, unsigned long long N>
    struct vector_at;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/detail/vector_fill.hpp>
#include <boost/mpl11/fwd/vector.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace vector_at_detail {
        template <typename Ignore>
        struct at_impl;

        template <typename ...Ignore>
        struct at_impl<vector<Ignore...>> {
            template <typename Nth>
            static Nth apply(Ignore..., no_decay<Nth>*, ...);
        };
    } // end namespace vector_at_detail

    template <typename ...An, unsigned long long N>
    struct vector_at<vector<An...>, N> {
        static_assert(N < sizeof...(An),
        "Accessing a `vector` at an out-of-bounds index.");

        using type = decltype(
            vector_at_detail::at_impl<
                typename vector_fill<N, void*>::type
            >::apply((no_decay<An>*)nullptr...)
        );
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VECTOR_AT_HPP
