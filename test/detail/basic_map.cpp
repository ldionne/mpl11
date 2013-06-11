/*!
 * @file
 * This file contains unit tests for `boost::mpl11::detail::basic_map`.
 */

#include <boost/mpl11/detail/basic_map.hpp>

#include <boost/type_traits/is_same.hpp>


template <typename First, typename Second>
struct pair {
    using first = First;
    using second = Second;
};

using namespace boost;
using boost::mpl11::detail::basic_map;

static_assert(!basic_map<>::has_key<struct k0>::type::value, "");

static_assert(basic_map<
    pair<struct k0, struct v0>
>::has_key<struct k0>::type::value, "");

static_assert(basic_map<
    pair<struct k0, struct v0>,
    pair<struct k1, struct v1>
>::has_key<struct k1>::type::value, "");


static_assert(is_same<
    basic_map<
        pair<struct k0, struct v0>
    >::at<struct k0>::type,
    struct v0
>::value, "");

static_assert(is_same<
    basic_map<
        pair<struct k0, struct v0>,
        pair<struct k1, struct v1>
    >::at<struct k1>::type,
    struct v1
>::value, "");

static_assert(is_same<
    basic_map<>::at<struct k0, struct default_>::type,
    struct default_
>::value, "");


static_assert(basic_map<>::empty::type::value, "");
static_assert(!basic_map<pair<struct k0, struct v0>>::empty::type::value, "");


static_assert(basic_map<>::size::type::value == 0, "");
static_assert(basic_map<pair<struct k0, struct v0>>::size::type::value == 1, "");
static_assert(basic_map<pair<struct k0, struct v0>, pair<struct k1, struct v1>>::size::type::value == 2, "");


static_assert(is_same<
    basic_map<>::begin::type,
    basic_map<>::end::type
>::value, "");

static_assert(!is_same<
    basic_map<pair<struct k0, struct v0>>::begin::type,
    basic_map<pair<struct k0, struct v0>>::end::type
>::value, "");

static_assert(is_same<
    basic_map<pair<struct k0, struct v0>>::begin::type::next::type,
    basic_map<pair<struct k0, struct v0>>::end::type
>::value, "");


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
template class basic_map<pair<struct k0, struct v0>>;
template class basic_map<pair<struct k0, struct v0>, pair<struct k1, struct v1>>;
}}}}

int main() { }
