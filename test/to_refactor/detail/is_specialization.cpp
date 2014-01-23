/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::is_specialization`.
 */

#include <boost/mpl11/detail/is_specialization.hpp>


using boost::mpl11::detail::is_specialization;

template <typename T, bool IsSpecialization>
class test_qualifiers {
    static_assert(is_specialization<T>::value == IsSpecialization, "");
    static_assert(!is_specialization<T&>::value, "");
    static_assert(!is_specialization<T volatile>::value, "");
    static_assert(!is_specialization<T const>::value, "");
    static_assert(!is_specialization<T const volatile>::value, "");
};

template <typename>
struct unary_template;

template <typename, typename>
struct binary_template;

template <typename ...>
struct variadic_template;

template <typename = struct default_parameter>
struct defaulted_template;

template <int ...>
struct non_type_template;

struct test_all
      : test_qualifiers<struct non_template, false>,
      test_qualifiers<unary_template<struct x>, true>,
      test_qualifiers<binary_template<struct x, struct y>, true>,
      test_qualifiers<defaulted_template<>, true>,

      test_qualifiers<variadic_template<>, true>,
      test_qualifiers<variadic_template<struct x>, true>,
      test_qualifiers<variadic_template<struct x, struct y>, true>,
      test_qualifiers<variadic_template<struct x, struct y, struct z>, true>,

      test_qualifiers<non_type_template<>, false>,
      test_qualifiers<non_type_template<1>, false>,
      test_qualifiers<non_type_template<1, 2>, false>,
      test_qualifiers<non_type_template<1, 2, 3>, false>
{ };


int main() { }
