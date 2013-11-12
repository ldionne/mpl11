/*!
 * @file
 * Defines `boost::mpl11::detail::variadic::slice`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_SLICE_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_SLICE_HPP

namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    /*!
     * @ingroup details
     *
     * Returns a `variadic::pack` containing all the elements in
     * the range [`First`, `Last`).
     */
    template <typename Pack, unsigned long long First,unsigned long long Last>
    struct slice;
}}}} // end namespace boost::mpl11::detail::variadic


#include <boost/mpl11/detail/variadic/drop.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>
#include <boost/mpl11/detail/variadic/take.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    namespace slice_detail {
        enum class optimization {
            empty_slice, until_end, from_start, none
        };

        using Index = unsigned long long;

        template <typename Pack, Index First, Index Last, optimization>
        struct slice_impl;

        template <typename ...An, Index First, Index Last>
        struct slice_impl<pack<An...>, First, Last,optimization::empty_slice>{
            using type = pack<>;
        };

        template <typename ...An, Index First, Index Last>
        struct slice_impl<pack<An...>, First, Last, optimization::none>
            : take<
                typename drop<pack<An...>, First>::type, Last - First
            >
        { };

        template <typename ...An, Index First, Index Last>
        struct slice_impl<pack<An...>, First, Last, optimization::until_end>
            : drop<pack<An...>, First>
        { };

        template <typename ...An, Index First, Index Last>
        struct slice_impl<pack<An...>, First, Last, optimization::from_start>
            : take<pack<An...>, Last>
        { };
    } // end namespace slice_detail

    template <
        typename ...An,
        unsigned long long First,
        unsigned long long Last
    >
    struct slice<pack<An...>, First, Last> {
        static_assert(First <= Last,
        "Parameter pack slice has invalid bounds: First > Last.");

        static_assert(Last <= sizeof...(An),
        "Parameter pack slice ends after the end of the pack itself.");

        using type = typename slice_detail::slice_impl<
            pack<An...>, First, Last,
            First == Last         ? slice_detail::optimization::empty_slice :
            Last == sizeof...(An) ? slice_detail::optimization::until_end   :
            First == 0            ? slice_detail::optimization::from_start  :
            /* else */              slice_detail::optimization::none
        >::type;
    };
}}}} // end namespace boost::mpl11::detail::variadic

#endif // !BOOST_MPL11_DETAIL_VARIADIC_SLICE_HPP
