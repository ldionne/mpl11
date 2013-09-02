/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::vector`.
 */

#include <boost/mpl11/container/vector.hpp>

#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsics.hpp>


using namespace boost::mpl11;
using namespace intrinsic;

template <typename Sequence, typename ...T>
struct variadic_push_back
    : identity<Sequence>
{ };

template <typename Sequence, typename Head, typename ...Tail>
struct variadic_push_back<Sequence, Head, Tail...>
    : variadic_push_back<
        typename push_back<Sequence, Head>::type,
        Tail...
    >
{ };

struct a0; struct a1; struct a2;

template <typename EmptySequence>
class random_access_sequence_test {
    template <typename ...T>
    using Sequence = typename variadic_push_back<EmptySequence, T...>::type;

    // equal_to
    static_assert(equal_to<
        Sequence<>,
        Sequence<>
    >::type::value, "");
    static_assert(equal_to<
        Sequence<a0>,
        Sequence<a0>
    >::type::value, "");
    static_assert(equal_to<
        Sequence<a0, a1>,
        Sequence<a0, a1>
    >::type::value, "");

    // not_equal_to
    static_assert(not_equal_to<
        Sequence<a0>,
        Sequence<>
    >::type::value, "");
    static_assert(not_equal_to<
        Sequence<a0>,
        Sequence<a1>
    >::type::value, "");

    // is_empty
    static_assert(is_empty<Sequence<>>::type::value, "");
    static_assert(!is_empty<Sequence<a0>>::type::value, "");
    static_assert(!is_empty<Sequence<a0, a1>>::type::value, "");

    // size
    static_assert(size<Sequence<>>::type::value == 0, "");
    static_assert(size<Sequence<a0>>::type::value == 1, "");
    static_assert(size<Sequence<a0, a1>>::type::value == 2, "");

    // front
    static_assert(equal_to<
        typename front<Sequence<a0>>::type,
        a0
    >::type::value, "");
    static_assert(equal_to<
        typename front<Sequence<a0, a1>>::type,
        a0
    >::type::value, "");
    static_assert(equal_to<
        typename front<Sequence<a0, a1, a2>>::type,
        a0
    >::type::value, "");

    // back
    static_assert(equal_to<
        typename back<Sequence<a0>>::type,
        a0
    >::type::value, "");
    static_assert(equal_to<
        typename back<Sequence<a0, a1>>::type,
        a1
    >::type::value, "");
    static_assert(equal_to<
        typename back<Sequence<a0, a1, a2>>::type,
        a2
    >::type::value, "");

    // clear
    static_assert(equal_to<
        typename clear<Sequence<>>::type,
        Sequence<>
    >::type::value, "");
    static_assert(equal_to<
        typename clear<Sequence<a0>>::type,
        Sequence<>
    >::type::value, "");
    static_assert(equal_to<
        typename clear<Sequence<a0, a1>>::type,
        Sequence<>
    >::type::value, "");

    // push_front
    static_assert(equal_to<
        typename push_front<Sequence<>, a0>::type,
        Sequence<a0>
    >::type::value, "");
    static_assert(equal_to<
        typename push_front<Sequence<a1>, a0>::type,
        Sequence<a0, a1>
    >::type::value, "");
    static_assert(equal_to<
        typename push_front<Sequence<a1, a2>, a0>::type,
        Sequence<a0, a1, a2>
    >::type::value, "");

    // push_back
    static_assert(equal_to<
        typename push_back<Sequence<>, a0>::type,
        Sequence<a0>
    >::type::value, "");
    static_assert(equal_to<
        typename push_back<Sequence<a0>, a1>::type,
        Sequence<a0, a1>
    >::type::value, "");
    static_assert(equal_to<
        typename push_back<Sequence<a0, a1>, a2>::type,
        Sequence<a0, a1, a2>
    >::type::value, "");

    // pop_back
    static_assert(equal_to<
        typename pop_back<Sequence<a0>>::type,
        Sequence<>
    >::type::value, "");
    static_assert(equal_to<
        typename pop_back<Sequence<a0, a1>>::type,
        Sequence<a0>
    >::type::value, "");

    // pop_front
    static_assert(equal_to<
        typename pop_front<Sequence<a0>>::type,
        Sequence<>
    >::type::value, "");
    static_assert(equal_to<
        typename pop_front<Sequence<a0, a1>>::type,
        Sequence<a1>
    >::type::value, "");

    // at/at_c
    static_assert(equal_to<
        typename at_c<Sequence<a0>, 0>::type,
        a0
    >::type::value, "");
    static_assert(equal_to<
        typename at_c<Sequence<a0, a1>, 0>::type,
        a0
    >::type::value, "");
    static_assert(equal_to<
        typename at_c<Sequence<a0, a1>, 1>::type,
        a1
    >::type::value, "");

    // begin/end
    static_assert(equal_to<
        typename begin<Sequence<>>::type,
        typename end<Sequence<>>::type
    >::type::value, "");
    static_assert(not_equal_to<
        typename begin<Sequence<a0>>::type,
        typename end<Sequence<a0>>::type
    >::type::value, "");
    static_assert(not_equal_to<
        typename end<Sequence<a0>>::type,
        typename end<Sequence<>>::type
    >::type::value, "");

    // next/prior
    static_assert(equal_to<
        typename next<typename begin<Sequence<a0>>::type>::type,
        typename end<Sequence<a0>>::type
    >::type::value, "");
    static_assert(equal_to<
        typename prior<typename end<Sequence<a0>>::type>::type,
        typename begin<Sequence<a0>>::type
    >::type::value, "");

    // deref
    static_assert(equal_to<
        typename deref<typename begin<Sequence<a0>>::type>::type,
        a0
    >::type::value, "");
};


int main() {
    static_assert(sizeof(random_access_sequence_test<container::vector<>>), "");
}
