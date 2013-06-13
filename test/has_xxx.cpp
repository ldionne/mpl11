/*!
 * @file
 * This file contains unit tests for the SFINAE metafunction generators.
 */

#include <boost/mpl11/has_xxx.hpp>


BOOST_MPL11_HAS_NESTED_TYPE(has_type, type)
struct no_nested_type { };
struct nested_type { struct type; };
struct nested_template_type { template <typename ...> struct type; };

static_assert(!has_type<no_nested_type>::value, "");
static_assert(!has_type<nested_template_type>::value, "");
static_assert(has_type<nested_type>::value, "");


int main() { }
