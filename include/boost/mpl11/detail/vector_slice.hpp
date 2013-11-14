/*!
 * @file
 * Defines `boost::mpl11::detail::vector_slice`.
 */

#ifndef BOOST_MPL11_DETAIL_VECTOR_SLICE_HPP
#define BOOST_MPL11_DETAIL_VECTOR_SLICE_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns a `mpl11::vector` containing all the elements in
     * the range [`First`, `Last`).
     */
    template <
        typename Vector,
        unsigned long long First,
        unsigned long long Last
    >
    struct vector_slice;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/vector_drop.hpp>
#include <boost/mpl11/detail/vector_take.hpp>
#include <boost/mpl11/fwd/vector.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace vector_slice_detail {
        enum class optim {
            empty_slice, until_end, from_start, none
        };

        using Index = unsigned long long;

        template <typename Vector, Index First, Index Last, optim>
        struct slice_impl;

        template <typename Vector, Index First, Index Last>
        struct slice_impl<Vector, First, Last, optim::empty_slice> {
            using type = vector<>;
        };

        template <typename Vector, Index First, Index Last>
        struct slice_impl<Vector, First, Last, optim::none>
            : vector_take<
                typename vector_drop<Vector, First>::type, Last - First
            >
        { };

        template <typename Vector, Index First, Index Last>
        struct slice_impl<Vector, First, Last, optim::until_end>
            : vector_drop<Vector, First>
        { };

        template <typename Vector, Index First, Index Last>
        struct slice_impl<Vector, First, Last, optim::from_start>
            : vector_take<Vector, Last>
        { };
    } // end namespace vector_slice_detail

    template <
        typename ...An,
        unsigned long long First,
        unsigned long long Last
    >
    struct vector_slice<vector<An...>, First, Last> {
        static_assert(First <= Last,
        "`vector` slice has invalid bounds: First > Last.");

        static_assert(Last <= sizeof...(An),
        "`vector` slice ends after the end of the `vector` itself.");

        using type = typename vector_slice_detail::slice_impl<
            vector<An...>, First, Last,
            First == Last         ? vector_slice_detail::optim::empty_slice :
            Last == sizeof...(An) ? vector_slice_detail::optim::until_end   :
            First == 0            ? vector_slice_detail::optim::from_start  :
            /* else */              vector_slice_detail::optim::none
        >::type;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VECTOR_SLICE_HPP
