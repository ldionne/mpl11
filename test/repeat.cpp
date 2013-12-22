/*!
 * @file
 * Contains unit tests for `boost::mpl11::repeat`.
 */

#include <boost/mpl11/repeat.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/has_optimization.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

template <detail::std_size_t N, typename T>
struct test_repeat {
    template <typename ...U>
    struct equals {
        static_assert(equal<vector<U...>, repeat_c<T, N>>::value, "");
        static_assert(equal<vector<U...>, repeat_c_t<T, N>>::value, "");

        static_assert(is_empty<repeat_c<T, N>>::value == (sizeof...(U) == 0), "");
        static_assert(is_empty<repeat_c_t<T, N>>::value == (sizeof...(U) == 0), "");

        static_assert(length<repeat_c<T, N>>::value == sizeof...(U), "");
        static_assert(length<repeat_c_t<T, N>>::value == sizeof...(U), "");

        static_assert(equal<
            vector<U...>,
            unpack_t<repeat_c<T, N>, into<vector>>
        >::value, "");

        static_assert(has_optimization<
            repeat_c<T, N>, optimization::O1_length
        >::value, "");
    };
};

struct x;
struct test_all :
    test_repeat<0, x>::equals<>,
    test_repeat<1, x>::equals<x>,
    test_repeat<2, x>::equals<x, x>,
    test_repeat<3, x>::equals<x, x, x>,
    test_repeat<4, x>::equals<x, x, x, x>,
    test_repeat<5, x>::equals<x, x, x, x, x>,

    test_repeat<11, x>::equals<x, x, x, x, x, x, x, x, x, x, x>
{ };


int main() { }
