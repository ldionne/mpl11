/*!
 * @file
 * Contains unit tests for `boost::mpl11::integral_c`.
 */

#include <boost/mpl11/integral_c.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename T, T v = T{}>
struct test_one {
    using I = integral_c<T, v>;

    static_assert(is_same<typename I::value_type, T>::value, "");

    static_assert(I::value == v, "");

    static_assert(is_same<typename I::type, I>::value, "");

    static constexpr typename I::value_type c1 = I{};
    static_assert(c1 == v, "");

    static constexpr typename I::value_type c2 = I{}();
    static_assert(c2 == v, "");
};

struct tests :
    test_one<bool>,
    test_one<char>,
    test_one<short>,
    test_one<int>,
    test_one<long>,
    test_one<long long>,

    test_one<unsigned char>,
    test_one<unsigned short>,
    test_one<unsigned int>,
    test_one<unsigned long>,
    test_one<unsigned long long>
{ };


int main() { }
