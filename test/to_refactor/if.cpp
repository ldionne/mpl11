/*!
 * @file
 * Contains unit tests for `boost::mpl11::if_` et al.
 */

#include <boost/mpl11/if.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct Then { struct type; };
struct Else { struct type; };
struct yes { struct type { static constexpr long value = 10; }; };
struct no { struct type { static constexpr long value = 0; }; };


// if_
static_assert(is_same<if_<yes,     Then, Else>::type, Then::type>::value, "");
static_assert(is_same<if_t<yes,    Then, Else>,       Then::type>::value, "");
static_assert(is_same<if_c<true,   Then, Else>::type, Then::type>::value, "");
static_assert(is_same<if_c_t<true, Then, Else>,       Then::type>::value, "");

static_assert(is_same<if_<no,       Then, Else>::type, Else::type>::value, "");
static_assert(is_same<if_t<no,      Then, Else>,       Else::type>::value, "");
static_assert(is_same<if_c<false,   Then, Else>::type, Else::type>::value, "");
static_assert(is_same<if_c_t<false, Then, Else>,       Else::type>::value, "");


// else_if
static_assert(is_same<else_if<yes,      Then, Else>::type, Then::type>::value, "");
static_assert(is_same<else_if_t<yes,    Then, Else>,       Then::type>::value, "");
static_assert(is_same<else_if_c<true,   Then, Else>::type, Then::type>::value, "");
static_assert(is_same<else_if_c_t<true, Then, Else>,       Then::type>::value, "");

static_assert(is_same<else_if<no,        Then, Else>::type, Else::type>::value, "");
static_assert(is_same<else_if_t<no,      Then, Else>,       Else::type>::value, "");
static_assert(is_same<else_if_c<false,   Then, Else>::type, Else::type>::value, "");
static_assert(is_same<else_if_c_t<false, Then, Else>,       Else::type>::value, "");


// else_
static_assert(is_same<else_<Else>::type, Else::type>::value, "");
static_assert(is_same<else_t<Else>,      Else::type>::value, "");


// Combined if_, else_if and else_
struct Undefined;

static_assert(is_same<
    if_<no,
        Undefined
    , else_if<no,
        Undefined
    , else_<
        Then
    >>>::type,
    Then::type
>::value, "");

static_assert(is_same<
    if_<no,
        Undefined
    , else_if<yes,
        Then
    , else_<
        Undefined
    >>>::type,
    Then::type
>::value, "");

static_assert(is_same<
    if_<yes,
        Then
    , else_if<no,
        Undefined
    , else_<
        Undefined
    >>>::type,
    Then::type
>::value, "");

static_assert(is_same<
    if_<yes,
        Then
    , else_if<yes,
        Undefined
    , else_<
        Undefined
    >>>::type,
    Then::type
>::value, "");


int main() { }
