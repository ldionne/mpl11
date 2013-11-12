/*!
 * @file
 * Defines `boost::mpl11::detail::variadic::take`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_TAKE_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_TAKE_HPP

namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    /*!
     * @ingroup details
     *
     * Returns a `variadic::pack` containing all the elements in
     * the range [`0`, `N`).
     *
     *
     * @internal
     * If `N < O1_TAKE`, this algorithm is O(1).
     * Otherwise, it is O(3 * floor(N / O1_TAKE)).
     */
    template <typename Pack, unsigned long long N>
    struct take;
}}}} // end namespace boost::mpl11::detail::variadic


#include <boost/mpl11/detail/variadic/concat.hpp>
#include <boost/mpl11/detail/variadic/drop.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


namespace boost { namespace mpl11 { namespace detail { namespace variadic {
    namespace take_detail {
        // IMPORTANT:
        // Always keep this synced with O1_TAKE below (in the script).
        // Whenever this value is changed, the value in the below script
        // must be adjusted and the specializations must be re-generated.
        //
        // Also, the unit test in <test/detail/variadic/take.cpp> shoud be
        // adjusted whenever this is modified.
        static constexpr unsigned long long O1_TAKE = 10;

        template <typename Pack, unsigned long long N, bool = (N < O1_TAKE)>
        struct take_impl;

        template <typename ...An, unsigned long long N>
        struct take_impl<pack<An...>, N, false>
            : concat<
                typename take_impl<
                    pack<An...>, O1_TAKE
                >::type,
                typename take_impl<
                    typename drop<pack<An...>, O1_TAKE>::type, N-O1_TAKE
                >::type
            >
        { };

        // Script generating specializations to speed up `take_impl`.
        // This is only of importance to the maintainer of the library;
        // you should not touch this.

/*****************************************************************************

#!/usr/bin/env ruby

# IMPORTANT: See the above notice about the modification of O1_TAKE.
O1_TAKE = 10

for n in 0..O1_TAKE do
    decl = (0..n-1).collect { |i| "typename A#{i}" } << "typename ...An"
    spec = (0..n-1).collect { |i| "A#{i}" } << "An..."
    take = (0..n-1).collect { |i| "A#{i}" }

    puts <<-END
template <#{decl.join(', ')}> \
struct take_impl<pack<#{spec.join(', ')}>, #{n}> { \
    using type = pack<#{take.join(', ')}>; \
};
    END
end

*****************************************************************************/

        //////////////////////////////////////////////////////////////////////
        // BEGIN GENERATED OUTPUT. DO NOT EDIT!
        //////////////////////////////////////////////////////////////////////
        template <typename ...An> struct take_impl<pack<An...>, 0> {     using type = pack<>; };
        template <typename A0, typename ...An> struct take_impl<pack<A0, An...>, 1> {     using type = pack<A0>; };
        template <typename A0, typename A1, typename ...An> struct take_impl<pack<A0, A1, An...>, 2> {     using type = pack<A0, A1>; };
        template <typename A0, typename A1, typename A2, typename ...An> struct take_impl<pack<A0, A1, A2, An...>, 3> {     using type = pack<A0, A1, A2>; };
        template <typename A0, typename A1, typename A2, typename A3, typename ...An> struct take_impl<pack<A0, A1, A2, A3, An...>, 4> {     using type = pack<A0, A1, A2, A3>; };
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename ...An> struct take_impl<pack<A0, A1, A2, A3, A4, An...>, 5> {     using type = pack<A0, A1, A2, A3, A4>; };
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename ...An> struct take_impl<pack<A0, A1, A2, A3, A4, A5, An...>, 6> {     using type = pack<A0, A1, A2, A3, A4, A5>; };
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename ...An> struct take_impl<pack<A0, A1, A2, A3, A4, A5, A6, An...>, 7> {     using type = pack<A0, A1, A2, A3, A4, A5, A6>; };
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename ...An> struct take_impl<pack<A0, A1, A2, A3, A4, A5, A6, A7, An...>, 8> {     using type = pack<A0, A1, A2, A3, A4, A5, A6, A7>; };
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename ...An> struct take_impl<pack<A0, A1, A2, A3, A4, A5, A6, A7, A8, An...>, 9> {     using type = pack<A0, A1, A2, A3, A4, A5, A6, A7, A8>; };
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename ...An> struct take_impl<pack<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, An...>, 10> {     using type = pack<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>; };
        //////////////////////////////////////////////////////////////////////
        // END GENERATED OUTPUT
        //////////////////////////////////////////////////////////////////////
    } // end namespace take_detail

    template <typename ...An, unsigned long long N>
    struct take<pack<An...>, N> {
        static_assert(N <= sizeof...(An),
        "Taking more elements in a parameter pack than the size "
        "of the pack.");

        using type = typename take_detail::take_impl<
            pack<An...>, N
        >::type;
    };
}}}} // end namespace boost::mpl11::detail::variadic

#endif // !BOOST_MPL11_DETAIL_VARIADIC_TAKE_HPP
