/*!
 * @file
 * Contains unit tests for `boost::mpl11::replicate`.
 */

#include <boost/mpl11/replicate.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

template <unsigned long long N, typename T>
struct test_replicate {
    template <typename ...U>
    struct equals {
        static_assert(equal<vector<U...>, replicate_c<N, T>>::value, "");
        static_assert(equal<vector<U...>, replicate_c_t<N, T>>::value, "");
    };
};

struct x;
struct test_all :
    test_replicate<0, x>::equals<>,
    test_replicate<1, x>::equals<x>,
    test_replicate<2, x>::equals<x, x>,
    test_replicate<3, x>::equals<x, x, x>,
    test_replicate<4, x>::equals<x, x, x, x>,
    test_replicate<5, x>::equals<x, x, x, x, x>,

    test_replicate<11, x>::equals<x, x, x, x, x, x, x, x, x, x, x>
{ };


int main() { }
