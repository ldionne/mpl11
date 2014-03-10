/*!
 * @file
 * Contains unit tests for the @ref Foldable typeclass.
 */

#include <boost/mpl11/foldable.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>

#include "minimal_foldable.hpp"
#include "test_method_dispatch.hpp"


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Foldable<Archetype<>> : instantiate<Foldable>::with<Archetype<>> {
        template <typename, typename, typename>
        using foldr_impl = method_tag<foldr>;

        template <typename, typename, typename>
        using foldl_impl = method_tag<foldl>;

        template <typename, typename>
        using foldr1_impl = method_tag<foldr1>;

        template <typename, typename>
        using foldl1_impl = method_tag<foldl1>;
    };
}}

struct test_dispatching
    : method<foldr, undefined, undefined, archetype<>>
    , method<foldl, undefined, undefined, archetype<>>
    , method<foldr1, undefined, archetype<>>
    , method<foldl1, undefined, archetype<>>
{ };

namespace test_all_any_none {
    template <typename pred>
    struct with_predicate;

    template <
        template <typename ...> class f,
        typename pred, bool result, typename ...xs
    >
    struct check_pred
        : with_predicate<pred>::template with_input<xs...>
        , with_predicate<pred>
    {
        static_assert(f<pred, minimal_foldable<xs...>>::value == result, "");
    };

    template <typename pred>
    struct with_predicate {
        template <typename ...xs>
        struct with_input {
            template <bool result>
            using all_is = check_pred<all, pred, result, xs...>;

            template <bool result>
            using any_is = check_pred<any, pred, result, xs...>;

            template <bool result>
            using none_is = check_pred<none, pred, result, xs...>;
        };
    };

    struct t; struct x; struct y; struct z;
    struct tests
        : with_predicate<undefined>
            ::with_input<>
                ::all_is<true>
                ::any_is<false>
                ::none_is<true>

        , with_predicate<always<false_>>
            ::with_input<undefined>
                ::all_is<false>
                ::any_is<false>
                ::none_is<true>

            ::with_input<undefined, undefined>
                ::all_is<false>
                ::any_is<false>
                ::none_is<true>

        , with_predicate<always<true_>>
            ::with_input<undefined>
                ::all_is<true>
                ::any_is<true>
                ::none_is<false>

            ::with_input<undefined, undefined>
                ::all_is<true>
                ::any_is<true>
                ::none_is<false>

        , with_predicate<partial<quote<std_is_same>, t>>
            ::with_input<t>
                ::all_is<true>
                ::any_is<true>
                ::none_is<false>
            ::with_input<x>
                ::all_is<false>
                ::any_is<false>
                ::none_is<true>
            ::with_input<t, t>
                ::all_is<true>
                ::any_is<true>
                ::none_is<false>
            ::with_input<t, y>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<x, t>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<x, y>
                ::all_is<false>
                ::any_is<false>
                ::none_is<true>
            ::with_input<t, t, t>
                ::all_is<true>
                ::any_is<true>
                ::none_is<false>
            ::with_input<t, t, z>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<t, y, t>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<t, y, z>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<x, t, t>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<x, t, z>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<x, y, t>
                ::all_is<false>
                ::any_is<true>
                ::none_is<false>
            ::with_input<x, y, z>
                ::all_is<false>
                ::any_is<false>
                ::none_is<true>
    { };
} // end namespace test_all_any_none

namespace test_all_any_none_of {
    template <typename ...xs>
    struct with_input;

    template <template <typename ...> class f, bool result, typename ...xs>
    struct check_no_pred : with_input<xs...> {
        static_assert(f<minimal_foldable<xs...>>::value == result, "");
    };

    template <typename ...xs>
    struct with_input {
        template <bool result>
        using all_is = check_no_pred<all_of, result, xs...>;

        template <bool result>
        using any_is = check_no_pred<any_of, result, xs...>;

        template <bool result>
        using none_is = check_no_pred<none_of, result, xs...>;
    };

    struct tests
        : with_input<>
            ::all_is<true>
            ::any_is<false>
            ::none_is<true>

        , with_input<true_>
            ::all_is<true>
            ::any_is<true>
            ::none_is<false>

        , with_input<false_>
            ::all_is<false>
            ::any_is<false>
            ::none_is<true>

        , with_input<true_, true_>
            ::all_is<true>
            ::any_is<true>
            ::none_is<false>

        , with_input<true_, false_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<false_, true_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<false_, false_>
            ::all_is<false>
            ::any_is<false>
            ::none_is<true>

        , with_input<true_, true_, true_>
            ::all_is<true>
            ::any_is<true>
            ::none_is<false>

        , with_input<true_, true_, false_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<true_, false_, true_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<true_, false_, false_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<false_, true_, true_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<false_, true_, false_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<false_, false_, true_>
            ::all_is<false>
            ::any_is<true>
            ::none_is<false>

        , with_input<false_, false_, false_>
            ::all_is<false>
            ::any_is<false>
            ::none_is<true>
    { };
} // end namespace test_all_any_none_of

namespace test_sum_product {
    template <int ...xs>
    struct check {
        using structure = minimal_foldable<int_<xs>...>;
        template <int sum_, int prod>
        struct sum_prod {
            static_assert(sum<structure>::value == sum_, "");
            static_assert(product<structure>::value == prod, "");
        };
    };

    struct tests
        : check<>::sum_prod<0, 1>
        , check<0>::sum_prod<0, 0>
        , check<1>::sum_prod<1, 1>
        , check<1, 2, 3>::sum_prod<1 + 2 + 3, 1 * 2 * 3>
        , check<1, 0, 3>::sum_prod<1 + 0 + 3, 1 * 0 * 3>
        , check<1, 4, 6, 8, -3>::sum_prod<1 + 4 + 6 + 8 - 3,
                                          1 * 4 * 6 * 8 * (-3)>
    { };
} // end namespace test_sum_product

namespace test_minimum_maximum {
    template <int ...xs>
    struct check {
        using structure = minimal_foldable<int_<xs>...>;
        template <int min, int max>
        struct minmax {
            static_assert(minimum_by<quote<less>, structure>::value == min, "");
            static_assert(maximum_by<quote<less>, structure>::value == max, "");
            static_assert(minimum<structure>::value == min, "");
            static_assert(maximum<structure>::value == max, "");
        };
    };

    struct tests
        : check<0>::minmax<0, 0>

        , check<0, 0>::minmax<0, 0>
        , check<0, 1>::minmax<0, 1>
        , check<1, 0>::minmax<0, 1>

        , check<0, 1, 2>::minmax<0, 2>
        , check<0, 1, 1>::minmax<0, 1>
        , check<2, 0, 1>::minmax<0, 2>
        , check<2, 1, 0>::minmax<0, 2>

        , check<2, 1, 0, 16, -2, 50>::minmax<-2, 50>
    { };
} // end namespace test_minimum_maximum

namespace test_unpack {
    template <typename ...> struct f { struct type; };

    template <int ...xs>
    struct unpacking {
        static_assert(std_is_same<
            typename unpack<minimal_foldable<int_<xs>...>, quote<f>>::type,
            typename f<int_<xs>...>::type
        >::value, "");
    };

    struct tests
        : unpacking<>
        , unpacking<0>
        , unpacking<0, 1>
        , unpacking<0, 1, 2>
        , unpacking<0, 1, 2, 3>
        , unpacking<0, 1, 2, 3, 4>
    { };
} // end namespace test_unpack


int main() { }
