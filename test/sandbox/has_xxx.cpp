/*!
 * @file
 * This file contains unit tests for the SFINAE metafunction generators.
 */

#include <boost/mpl11/has_xxx.hpp>


// Simple case with nested ::type
namespace nested_type {
    BOOST_MPL11_HAS_NESTED_TYPE(has_type, type)
    struct no1;
    struct no2 { };
    struct no3 { template <typename ...> struct type; };
    struct no4 { template <typename ...> struct type { }; };
    struct yes1 { struct type; };
    struct yes2 { struct type { }; };

    static_assert(!has_type<no1>::value, "");
    static_assert(!has_type<no2>::value, "");
    static_assert(!has_type<no3>::value, "");
    static_assert(!has_type<no4>::value, "");
    static_assert(has_type<yes1>::value, "");
    static_assert(has_type<yes2>::value, "");
}


// Try the macro with nested nested types.
namespace nested_type_type {
    BOOST_MPL11_HAS_NESTED_TYPE(has_foo_type, foo::type)

    struct no1;
    struct no2 { };
    struct no3 { struct foo; };
    struct no4 { struct foo { }; };
    struct no5 { template <typename ...> struct foo; };
    struct no6 { template <typename ...> struct foo { }; };
    struct no7 { template <typename ...> struct foo { struct type; }; };
    struct no8 { template <typename ...> struct foo { struct type { }; }; };

    struct yes1 { struct foo { struct type; }; };
    struct yes2 { struct foo { struct type { }; }; };

    static_assert(!has_foo_type<no1>::value, "");
    static_assert(!has_foo_type<no2>::value, "");
    static_assert(!has_foo_type<no3>::value, "");
    static_assert(!has_foo_type<no4>::value, "");
    static_assert(!has_foo_type<no5>::value, "");
    static_assert(!has_foo_type<no6>::value, "");
    static_assert(!has_foo_type<no7>::value, "");
    static_assert(!has_foo_type<no8>::value, "");

    static_assert(has_foo_type<yes1>::value, "");
    static_assert(has_foo_type<yes2>::value, "");
}


int main() { }
