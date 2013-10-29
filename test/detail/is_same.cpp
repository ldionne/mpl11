/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::is_same`.
 */

#include <boost/mpl11/detail/is_same.hpp>


using boost::mpl11::detail::is_same;

template <typename T>
class test_qualifiers {
    static_assert(is_same<T, T>::value, "");
    static_assert(!is_same<T, T&>::value, "");
    static_assert(!is_same<T, T volatile>::value, "");
    static_assert(!is_same<T, T const>::value, "");
    static_assert(!is_same<T, T const volatile>::value, "");

    template <typename U> struct different_from;
    static_assert(!is_same<T, different_from<T>>::value, "");
};

struct test_all
    : test_qualifiers<int>,
      test_qualifiers<float>,
      test_qualifiers<struct user_defined_type>
{ };


int main() { }
