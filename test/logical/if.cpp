/*!
 * @file
 * Contains unit tests for `boost::mpl11::if_` and friends.
 */

#include <boost/mpl11/logical.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct Then { struct type; };
struct Else { struct type; };
struct yes { struct type { static constexpr long value = 10; }; };
struct no { struct type { static constexpr long value = 0; }; };


// if_
static_assert(std_is_same<if_<yes,   Then, Else>::type, Then::type>::value, "");
static_assert(std_is_same<if_c<true, Then, Else>::type, Then::type>::value, "");

static_assert(std_is_same<if_<no,     Then, Else>::type, Else::type>::value, "");
static_assert(std_is_same<if_c<false, Then, Else>::type, Else::type>::value, "");


// else_if
static_assert(std_is_same<else_if<yes,    Then, Else>::type, Then::type>::value, "");
static_assert(std_is_same<else_if_c<true, Then, Else>::type, Then::type>::value, "");

static_assert(std_is_same<else_if<no,      Then, Else>::type, Else::type>::value, "");
static_assert(std_is_same<else_if_c<false, Then, Else>::type, Else::type>::value, "");


// else_
static_assert(std_is_same<else_<Else>::type, Else::type>::value, "");

// Combined if_, else_if and else_
static_assert(std_is_same<
    if_<no,
        undefined
    , else_if<no,
        undefined
    , else_<
        Then
    >>>::type,
    Then::type
>::value, "");

static_assert(std_is_same<
    if_<no,
        undefined
    , else_if<yes,
        Then
    , else_<
        undefined
    >>>::type,
    Then::type
>::value, "");

static_assert(std_is_same<
    if_<yes,
        Then
    , else_if<no,
        undefined
    , else_<
        undefined
    >>>::type,
    Then::type
>::value, "");

static_assert(std_is_same<
    if_<yes,
        Then
    , else_if<yes,
        undefined
    , else_<
        undefined
    >>>::type,
    Then::type
>::value, "");


int main() { }
