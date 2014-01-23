/*!
 * @file
 * Contains unit tests for the @ref Iterable typeclass.
 */

#include <boost/mpl11/iterable/iterable.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/iterable/snoc.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;
using detail::is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct archetype { struct type { struct mpl_tag; }; };
struct head_tag;
struct tail_tag;
struct is_empty_tag;
struct last_tag;
struct init_tag;
struct at_tag;
struct length_tag;
struct unpack_tag;

namespace boost { namespace mpl11 {
    template <>
    struct Iterable<archetype::type::mpl_tag> {
        template <typename> struct head_impl
        { using type = head_tag; };

        template <typename> struct tail_impl
        { using type = tail_tag; };

        template <typename> struct is_empty_impl : false_
        { using type = is_empty_tag; };

        template <typename> struct last_impl
        { using type = last_tag; };

        template <typename> struct init_impl
        { using type = init_tag; };

        template <typename, typename> struct at_impl
        { using type = at_tag; };

        template <typename> struct length_impl
        { using type = length_tag; };

        template <typename, typename>
        struct unpack_impl { using type = unpack_tag; };
    };
}} // end namespace boost::mpl11

struct index : size_t<0> { };
template <typename ...> struct result;
template <typename ...T>
struct f_ {
    using type = result<typename T::type...>;
};
using f = quote<f_>;
static_assert(is_same<head_t<archetype>,      head_tag>::value, "");
static_assert(is_same<tail_t<archetype>,      tail_tag>::value, "");
static_assert(is_same<is_empty_t<archetype>,  is_empty_tag>::value, "");
static_assert(is_same<last_t<archetype>,      last_tag>::value, "");
static_assert(is_same<init_t<archetype>,      init_tag>::value, "");
static_assert(is_same<at_t<archetype, index>, at_tag>::value, "");
static_assert(is_same<length_t<archetype>,    length_tag>::value, "");
static_assert(is_same<unpack_t<archetype, f>, unpack_tag>::value, "");


template <int> struct x { struct type; };

// Test the Foldable instantiation
template <int ...i>
struct test_folds {
    static_assert(equal<
        foldl<
            quote<snoc>,
            detail::minimal_iterable<>,
            detail::minimal_iterable<x<i>...>
        >,
        detail::minimal_iterable<x<i>...>
    >::value, "");

    static_assert(equal<
        foldr<
            quote<cons>,
            detail::minimal_iterable<>,
            detail::minimal_iterable<x<i>...>
        >,
        detail::minimal_iterable<x<i>...>
    >::value, "");
};

struct test_foldable :
    test_folds<>,
    test_folds<0>,
    test_folds<0, 1>,
    test_folds<0, 1, 2>,
    test_folds<0, 1, 2, 3>,
    test_folds<0, 1, 2, 3, 4>,
    test_folds<0, 1, 2, 3, 4, 5>,
    test_folds<0, 1, 2, 3, 4, 5, 6>,
    test_folds<0, 1, 2, 3, 4, 5, 6, 7>,
    test_folds<0, 1, 2, 3, 4, 5, 6, 7, 8>,
    test_folds<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>
{ };


// Test the Functor instantiation
template <int ...Seq>
struct test_fmap
    : detail::iterable_test<
        fmap<f, detail::minimal_iterable<x<Seq>...>>,
        apply<f, x<Seq>>...
    >
{ };

struct test_functor :
    test_fmap<>,
    test_fmap<0>,
    test_fmap<0, 1>,
    test_fmap<0, 1, 2>,
    test_fmap<0, 1, 2, 3>,
    test_fmap<0, 1, 2, 3, 4>,
    test_fmap<0, 1, 2, 3, 4, 5>
{ };


int main() { }
