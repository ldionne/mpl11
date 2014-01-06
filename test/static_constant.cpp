/*!
 * @file
 * Contains unit tests for `boost::mpl11::StaticConstant`.
 */

#include <boost/mpl11/static_constant.hpp>

#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;

template <typename T, T v>
struct minimal_static_constant : integral_c<T, v> {
    using mpl_tag = static_constant_tag;
};

template <typename X, typename Y = X>
struct test_static_constant {
    template <X v>
    using x = minimal_static_constant<X, v>;

    template <Y v>
    using y = minimal_static_constant<Y, v>;

    // Enumerable
    static_assert(succ_t<x<0>>::value == x<0>::value + 1, "");
    static_assert(pred_t<x<1>>::value == x<1>::value - 1, "");


    // Comparable
    static_assert( equal<x<0>, y<0>>::value, "");
    static_assert(!equal<x<0>, y<1>>::value, "");

    static_assert( not_equal<x<0>, y<1>>::value, "");
    static_assert(!not_equal<x<0>, y<0>>::value, "");


    // Orderable
    static_assert( less<x<0>, y<1>>::value, "");
    static_assert(!less<x<1>, y<0>>::value, "");
    static_assert(!less<x<0>, y<0>>::value, "");

    static_assert( less_equal<x<0>, y<1>>::value, "");
    static_assert( less_equal<x<1>, y<1>>::value, "");
    static_assert(!less_equal<x<1>, y<0>>::value, "");

    static_assert( greater<x<1>, y<0>>::value, "");
    static_assert(!greater<x<0>, y<1>>::value, "");
    static_assert(!greater<x<0>, y<0>>::value, "");

    static_assert(!greater_equal<x<0>, y<1>>::value, "");
    static_assert( greater_equal<x<1>, y<1>>::value, "");
    static_assert( greater_equal<x<1>, y<0>>::value, "");

    static_assert(min<x<0>, y<1>>::value == x<0>::value, "");
    static_assert(min<x<1>, y<0>>::value == y<0>::value, "");

    static_assert(max<x<0>, y<1>>::value == y<1>::value, "");
    static_assert(max<x<1>, y<0>>::value == x<1>::value, "");


    // Bitwise
    static constexpr Y max_y = static_cast<Y>(10);
    static constexpr X max_x = static_cast<X>(10);

    template <typename, typename, typename Dummy = void>
    struct bitwise_tests;

    template <X a, typename Dummy>
    struct bitwise_tests<x<a>, y<max_y>, Dummy>
        : bitwise_tests<x<a + 1>, y<0>>
    { };

    template <typename Dummy>
    struct bitwise_tests<x<max_x>, y<max_y>, Dummy> { };

    template <X a, Y b, typename Dummy>
    struct bitwise_tests<x<a>, y<b>, Dummy> : bitwise_tests<x<a>, y<b + 1>> {
        static_assert(bitand_<x<a>, y<b>>::value == (a & b), "");
        static_assert(bitor_<x<a>, y<b>>::value == (a | b), "");
        static_assert(bitxor<x<a>, y<b>>::value == (a ^ b), "");
        static_assert(compl_<x<a>>::value == ~a, "");
        static_assert(compl_<y<b>>::value == ~b, "");
    };

    static constexpr auto instantiate = sizeof(bitwise_tests<x<0>, y<0>>);

    static_assert(shift_left_c<x<(X)1>, 3>::value == ((X)1 << 3), "");
    static_assert(shift_right_c<x<(X)8>, 3>::value == ((X)8 >> 3), "");
};

struct tests :
    test_static_constant<bool>,
    test_static_constant<char>,
    test_static_constant<short>,
    test_static_constant<int>,
    test_static_constant<long>,
    test_static_constant<long long>,

    test_static_constant<unsigned char>,
    test_static_constant<unsigned short>,
    test_static_constant<unsigned int>,
    test_static_constant<unsigned long>,
    test_static_constant<unsigned long long>,

    test_static_constant<char, short>,
    test_static_constant<bool, long long> // could test more, but meh
{ };


int main() { }
