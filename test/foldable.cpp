/*!
 * @file
 * Contains unit tests for the @ref Foldable typeclass.
 */

#include <boost/mpl11/foldable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integral_c.hpp>
#include "minimal_foldable.hpp"


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct FoldableArchetype;
struct archetype { struct type { using mpl_datatype = FoldableArchetype; }; };
struct foldr_tag;
struct foldl_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Foldable<FoldableArchetype> {
        template <typename, typename, typename>
        struct foldr_impl { using type = foldr_tag; };

        template <typename, typename, typename>
        struct foldl_impl { using type = foldl_tag; };
    };
}} // end namespace boost::mpl11

static_assert(std_is_same<
    foldr<undefined, undefined, archetype>::type,
    foldr_tag
>::value, "");

static_assert(std_is_same<
    foldl<undefined, undefined, archetype>::type,
    foldl_tag
>::value, "");


//////////////////////////
// Test all, any and none
//////////////////////////
template <typename pred>
struct with_predicate;

template <
    template <typename ...> class f,
    typename pred, bool result, typename ...xs
>
struct check_pred : with_predicate<pred>::template with_input<xs...> {
    static_assert(f<pred, minimal_foldable<xs...>>::value == result, "");
};

template <typename pred>
struct with_predicate {
    template <typename ...xs>
    struct with_input {
        template <bool result>
        using all_is = check_pred<boost::mpl11::all, pred, result, xs...>;

        template <bool result>
        using any_is = check_pred<boost::mpl11::any, pred, result, xs...>;

        template <bool result>
        using none_is = check_pred<boost::mpl11::none, pred, result, xs...>;
    };
};

struct t; struct x; struct y; struct z;
struct tests_with_predicate :
    with_predicate<undefined>
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


///////////////////////////////////
// Test all_of, any_of and none_of
///////////////////////////////////
template <typename ...xs>
struct with_input;

template <template <typename ...> class f, bool result, typename ...xs>
struct check_no_pred : with_input<xs...> {
    static_assert(f<minimal_foldable<xs...>>::value == result, "");
};

template <typename ...xs>
struct with_input {
    template <bool result>
    using all_is = check_no_pred<boost::mpl11::all_of, result, xs...>;

    template <bool result>
    using any_is = check_no_pred<boost::mpl11::any_of, result, xs...>;

    template <bool result>
    using none_is = check_no_pred<boost::mpl11::none_of, result, xs...>;
};

struct tests_without_predicate :
    with_input<>
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


int main() { }
