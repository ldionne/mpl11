/*!
 * @file
 * Contains unit tests for `boost::mpl11::if_`.
 */

#include <boost/mpl11/if.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/has_type.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/equal_to.hpp>


using namespace boost::mpl11;
using detail::has_type;

struct Then;
struct Else;


// if_<Cond> (same as enable_if<Cond>)
static_assert(equal_to<
    if_<true_>::type,
    void
>::type::value, "");
static_assert(equal_to<
    apply<if_<_1>, true_>::type,
    void
>::type::value, "");
static_assert(!has_type<
    if_<false_>
>::type::value, "");


// if<Cond, Then, Else>
static_assert(equal_to<
    if_<true_, Then, Else>::type,
    Then
>::type::value, "");
static_assert(equal_to<
    apply<if_<_1, Then, Else>, true_>::type,
    Then
>::type::value, "");

static_assert(equal_to<
    if_<false_, Then, Else>::type,
    Else
>::type::value, "");
static_assert(equal_to<
    apply<if_<_1, Then, Else>, false_>::type,
    Else
>::type::value, "");


// if<Cond, Then>::else_if<Cond, Then, Else>
static_assert(equal_to<
    if_<false_, int>::else_if<true_, char, float>::type,
    char
>::type::value, "");
static_assert(equal_to<
    apply<if_<_1, int>::else_if<_2, char, float>, false_, true_>::type,
    char
>::type::value, "");

static_assert(equal_to<
    if_<false_, int>::else_if<false_, char, float>::type,
    float
>::type::value, "");
static_assert(equal_to<
    apply<if_<_1, int>::else_if<_2, char, float>, false_, false_>::type,
    float
>::type::value, "");

static_assert(equal_to<
    if_<true_, int>::else_if<false_, char, float>::type,
    int
>::type::value, "");
static_assert(equal_to<
    apply<if_<_1, int>::else_if<_2, char, float>, true_, false_>::type,
    int
>::type::value, "");


// nested else_if's
static_assert(equal_to<
    if_<true_,      struct _if>::
    else_if<false_, struct _else_if1>::
    else_if<false_, struct _else_if2>::
    else_<          struct _else>::type, struct _if
>::type::value, "");
static_assert(equal_to<
    if_<false_,     struct _if>::
    else_if<false_, struct _else_if1>::
    else_if<false_, struct _else_if2>::
    else_if<true_,  struct _else_if3>::
    else_<          struct _else>::type, struct _else_if3
>::type::value, "");
static_assert(equal_to<
    if_<false_,     struct _if>::
    else_if<true_,  struct _else_if1>::
    else_if<false_, struct _else_if2>::
    else_if<true_,  struct _else_if3>::
    else_<          struct _else>::type, struct _else_if1
>::type::value, "");


int main() { }
