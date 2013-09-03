/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::vector`.
 */

#include <boost/mpl11/container/vector.hpp>

#include <boost/mpl11/algorithm/advance.hpp>
#include <boost/mpl11/intrinsics.hpp>


using namespace boost::mpl11;
using namespace intrinsic;
using namespace algorithm;

struct a0; struct a1; struct a2; struct a3;

template <template <typename ...> class Sequence>
class forward_sequence_test {
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


    // size
    static_assert(size<Sequence<>>::type::value == 0, "");
    static_assert(size<Sequence<a0>>::type::value == 1, "");
    static_assert(size<Sequence<a0, a1>>::type::value == 2, "");


    // is_empty
    static_assert(is_empty<Sequence<>>::type::value, "");
    static_assert(!is_empty<Sequence<a0>>::type::value, "");
    static_assert(!is_empty<Sequence<a0, a1>>::type::value, "");


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


    // next
    static_assert(equal_to<
        typename next<typename begin<Sequence<a0>>::type>::type,
        typename end<Sequence<a0>>::type
    >::type::value, "");


    // deref
    static_assert(equal_to<
        typename deref<typename begin<Sequence<a0>>::type>::type,
        a0
    >::type::value, "");
};

template <template <typename ...> class Sequence>
class bidirectional_sequence_test : forward_sequence_test<Sequence> {
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


    // prior
    static_assert(equal_to<
        typename prior<typename end<Sequence<a0>>::type>::type,
        typename begin<Sequence<a0>>::type
    >::type::value, "");
};

template <template <typename ...> class Sequence>
class random_access_sequence_test : bidirectional_sequence_test<Sequence> {
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

    static_assert(equal_to<
        typename at_c<Sequence<a0, a1, a2>, 2>::type,
        a2
    >::type::value, "");
};

template <template <typename ...> class Sequence>
class extensible_sequence_test {
    using S = Sequence<a0, a1, a2, a3>;

    template <unsigned long i>
    using iter_at = typename advance_c<typename begin<S>::type, i>::type;

    // insert
    static_assert(equal_to<
        typename insert<S, iter_at<0>, int>::type,
        Sequence<int, a0, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert<S, iter_at<1>, int>::type,
        Sequence<a0, int, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert<S, iter_at<2>, int>::type,
        Sequence<a0, a1, int, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert<S, iter_at<3>, int>::type,
        Sequence<a0, a1, a2, int, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert<S, iter_at<4>, int>::type,
        Sequence<a0, a1, a2, a3, int>
    >::type::value, "");


    // insert_range
    static_assert(equal_to<
        typename insert_range<S, iter_at<0>, Sequence<int, float>>::type,
        Sequence<int, float, a0, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert_range<S, iter_at<1>, Sequence<int, float>>::type,
        Sequence<a0, int, float, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert_range<S, iter_at<2>, Sequence<int, float>>::type,
        Sequence<a0, a1, int, float, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert_range<S, iter_at<3>, Sequence<int, float>>::type,
        Sequence<a0, a1, a2, int, float, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename insert_range<S, iter_at<4>, Sequence<int, float>>::type,
        Sequence<a0, a1, a2, a3, int, float>
    >::type::value, "");


    // erase a single element
    static_assert(equal_to<
        typename erase<S, iter_at<0>>::type,
        Sequence<a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<1>>::type,
        Sequence<a0, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<2>>::type,
        Sequence<a0, a1, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<3>>::type,
        Sequence<a0, a1, a2>
    >::type::value, "");

    // erase with a range of iterators
    static_assert(equal_to<
        typename erase<S, iter_at<0>, iter_at<1>>::type,
        Sequence<a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<0>, iter_at<2>>::type,
        Sequence<a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<0>, iter_at<3>>::type,
        Sequence<a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<0>, iter_at<4>>::type,
        Sequence<>
    >::type::value, "");


    // erase with an empty range of iterators
    static_assert(equal_to<
        typename erase<S, iter_at<0>, iter_at<0>>::type,
        Sequence<a0, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<1>, iter_at<1>>::type,
        Sequence<a0, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<2>, iter_at<2>>::type,
        Sequence<a0, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<3>, iter_at<3>>::type,
        Sequence<a0, a1, a2, a3>
    >::type::value, "");

    static_assert(equal_to<
        typename erase<S, iter_at<4>, iter_at<4>>::type,
        Sequence<a0, a1, a2, a3>
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
};

template <template <typename ...> class Sequence>
class front_extensible_sequence_test : extensible_sequence_test<Sequence> {
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


    // pop_front
    static_assert(equal_to<
        typename pop_front<Sequence<a0>>::type,
        Sequence<>
    >::type::value, "");

    static_assert(equal_to<
        typename pop_front<Sequence<a0, a1>>::type,
        Sequence<a1>
    >::type::value, "");
};


template <template <typename ...> class Sequence>
class back_extensible_sequence_test : extensible_sequence_test<Sequence> {
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
};

template <template <typename ...> class Sequence>
class vector_test
    : front_extensible_sequence_test<Sequence>,
      back_extensible_sequence_test<Sequence>,
      random_access_sequence_test<Sequence>
{ };


int main() {
    static_assert(sizeof(vector_test<container::vector>), "");
}
