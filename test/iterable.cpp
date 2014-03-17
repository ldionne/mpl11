/*!
 * @file
 * Contains unit tests for the @ref Iterable typeclass.
 */

#include <boost/mpl11/iterable.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/dependent.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>
#include <boost/mpl11/logical.hpp>

#include "check_finite_iterable.hpp"
#include "check_foldable.hpp"
#include "minimal_iterable.hpp"
#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

namespace boost { namespace mpl11 {
    template <>
    struct Iterable<Archetype<>> : instantiate<Iterable>::with<Archetype<>> {
        template <typename>           using head_impl   = method_tag<head>;
        template <typename>           using tail_impl   = method_tag<tail>;
        template <typename>           using last_impl   = method_tag<last>;
        template <typename, typename> using at_impl     = method_tag<at>;
        template <typename>           using length_impl = method_tag<length>;

        template <typename>
        struct is_empty_impl : method_tag<is_empty> {
            // This is required to pass the assertions in other methods
            // like head and tail.
            static constexpr bool value = false;
        };
    };
}}

struct test_method_dispatching
    : method<head, archetype<>>
    , method<tail, archetype<>>
    , method<is_empty, archetype<>>
    , method<last, archetype<>>
    , method<at, int_<0>, archetype<>>
    , method<length, archetype<>>
{ };


namespace test_default_methods {
    using detail::std_is_same;

    template <typename ...xs>
    struct with_iterable {
        using reference = minimal_iterable<xs...>;
        static_assert(length<reference>::value == sizeof...(xs), "");
        template <typename ...>
        struct dependent {
            template <typename x>
            using type = typename x::type;
        };

        template <typename expected,
            typename actual = typename dependent<expected>::template type<
                last<reference>
            >
        >
        struct last_is
            : detail::dependent<expected>::template type<with_iterable>
        {
            static_assert(std_is_same<expected, actual>::value, "");
        };

        template <unsigned long index,
            typename actual = typename at_c<index, reference>::type>
        struct at {
            template <typename expected>
            struct is
                : detail::dependent<expected>::template type<with_iterable>
            {
                static_assert(std_is_same<expected, actual>::value, "");
            };
        };
    };

    struct tests
        : with_iterable<>                       //
        , with_iterable<undefined>              // checks length
        , with_iterable<undefined, undefined>   //

        , with_iterable<int_<0>>
            ::at<0>::is<int_<0>>
            ::last_is<int_<0>>
        , with_iterable<int_<0>, int_<1>>
            ::at<0>::is<int_<0>>
            ::at<1>::is<int_<1>>
            ::last_is<int_<1>>
        , with_iterable<int_<0>, int_<1>, int_<2>>
            ::at<0>::is<int_<0>>
            ::at<1>::is<int_<1>>
            ::at<2>::is<int_<2>>
            ::last_is<int_<2>>
    { };
} // end namespace test_default_methods

namespace test_comparable {
    template <int ...xs>
    struct compare {
        template <typename Dummy, int ...ys>
        struct with_ {
            static_assert(not_equal<
                minimal_iterable<int_<xs>...>,
                minimal_iterable<int_<ys>...>
            >::value, "");
        };

        template <typename Dummy>
        struct with_<Dummy, xs...> {
            static_assert(equal<
                minimal_iterable<int_<xs>...>,
                minimal_iterable<int_<xs>...>
            >::value, "");
        };

        template <int ...ys>
        using with = with_<void, ys...>;
    };

    struct tests :
          compare<>::with<>
        , compare<>::with<0>
        , compare<>::with<0, 1>
        , compare<>::with<0, 1, 2>

        , compare<0>::with<>
        , compare<0>::with<0>
        , compare<0>::with<0, 1>
        , compare<0>::with<0, 1, 2>

        , compare<0, 1>::with<>
        , compare<0, 1>::with<0>
        , compare<0, 1>::with<0, 1>
        , compare<0, 1>::with<0, 1, 2>

        , compare<0, 1, 2>::with<>
        , compare<0, 1, 2>::with<0>
        , compare<0, 1, 2>::with<0, 1>
        , compare<0, 1, 2>::with<0, 1, 2>
    { };
} // end namespace test_comparable

namespace test_orderable {
    template <int ...xs>
    struct check {
        template <template <typename ...> class comp>
        struct is {
            template <int ...ys>
            struct than
                : detail::dependent<int_<ys>...>::template type<check>
                , detail::dependent<int_<ys>...>::template type<is>
            {
                static_assert(comp<
                    minimal_iterable<int_<xs>...>,
                    minimal_iterable<int_<ys>...>
                >::value, "");
            };
        };
    };

    struct tests :
          check<>
            ::is<less>
                ::than<0>
                ::than<0, 1>
                ::than<0, 1, 2>
                ::than<0, 1, 2, 3>

            ::is<less_equal>
                ::than<>
                ::than<0>

        , check<0>::is<less>
            ::than<1>
            ::than<0, 0>
            ::than<0, 1>

        , check<0, 1>::is<less>
            ::than<1, 0>
            ::than<0, 2>

        , check<0, 1, 2>::is<less>
            ::than<0, 1, 3>
            ::than<0, 2>
            ::than<1>
    { };
} // end namespace test_orderable

namespace test_foldable {
    template <int ...xs>
    struct check
        : check_foldable<minimal_iterable<int_<xs>...>, int_<xs>...>
    { };

    struct tests
        : check<>
        , check<0>
        , check<0, 1>
        , check<0, 1, 2>
        , check<0, 1, 2, 3>
        , check<0, 1, 2, 3, 4>
    { };
} // end namespace test_foldable

namespace test_drop {
    template <unsigned n>
    struct dropping {
        template <int ...all>
        struct from {
            template <int ...remaining>
            struct is
                : check_finite_iterable<
                    drop_c<n, minimal_iterable<int_<all>...>>,
                    int_<remaining>...
                >
            { };
        };
    };

    struct tests
        : dropping<0>::from<>::is<>
        , dropping<1>::from<>::is<>
        , dropping<2>::from<>::is<>
        , dropping<3>::from<>::is<>

        , dropping<0>::from<0>::is<0>
        , dropping<1>::from<0>::is<>
        , dropping<2>::from<0>::is<>
        , dropping<3>::from<0>::is<>

        , dropping<0>::from<0, 1>::is<0, 1>
        , dropping<1>::from<0, 1>::is<1>
        , dropping<2>::from<0, 1>::is<>
        , dropping<3>::from<0, 1>::is<>

        , dropping<0>::from<0, 1, 2>::is<0, 1, 2>
        , dropping<1>::from<0, 1, 2>::is<1, 2>
        , dropping<2>::from<0, 1, 2>::is<2>
        , dropping<3>::from<0, 1, 2>::is<>
        , dropping<4>::from<0, 1, 2>::is<>
        , dropping<5>::from<0, 1, 2>::is<>

        , dropping<0>::from<0, 1, 2, 3>::is<0, 1, 2, 3>
        , dropping<1>::from<0, 1, 2, 3>::is<1, 2, 3>
        , dropping<2>::from<0, 1, 2, 3>::is<2, 3>
        , dropping<3>::from<0, 1, 2, 3>::is<3>
        , dropping<4>::from<0, 1, 2, 3>::is<>
        , dropping<5>::from<0, 1, 2, 3>::is<>
    { };
} // end namespace test_drop

namespace test_drop_while {
    template <int ...all>
    struct drop_leading_zeros_from {
        template <int ...remaining>
        struct is
            : check_finite_iterable<
                drop_while<lift<not_>, minimal_iterable<int_<all>...>>,
                int_<remaining>...
            >
        { };
    };

    struct tests
        : drop_leading_zeros_from<>::is<>

        , drop_leading_zeros_from<0>::is<>
        , drop_leading_zeros_from<1>::is<1>

        , drop_leading_zeros_from<0, 0>::is<>
        , drop_leading_zeros_from<0, 2>::is<2>
        , drop_leading_zeros_from<1, 0>::is<1, 0>
        , drop_leading_zeros_from<1, 2>::is<1, 2>

        , drop_leading_zeros_from<0, 0, 0>::is<>
        , drop_leading_zeros_from<0, 0, 3>::is<3>
        , drop_leading_zeros_from<0, 2, 0>::is<2, 0>
        , drop_leading_zeros_from<0, 2, 3>::is<2, 3>
        , drop_leading_zeros_from<1, 0, 0>::is<1, 0, 0>
        , drop_leading_zeros_from<1, 0, 3>::is<1, 0, 3>
        , drop_leading_zeros_from<1, 2, 0>::is<1, 2, 0>
        , drop_leading_zeros_from<1, 2, 3>::is<1, 2, 3>
    { };
} // end namespace test_drop_while


int main() { }
