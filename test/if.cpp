/*!
 * @file
 * Contains unit tests for `boost::mpl11::if_`.
 */

#include <boost/mpl11/if.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/has_type.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::has_type;
using detail::is_same;

struct Then;
struct Else;


// if_<Cond> (same as enable_if<Cond>)
static_assert(is_same<if_<true_>::type, void>::value, "");
static_assert(is_same<apply<if_<_1>, true_>::type, void>::value, "");
static_assert(!has_type<if_<false_>>::value, "");


// if<Cond, Then, Else>
static_assert(is_same<if_<true_, Then, Else>::type, Then>::value, "");
static_assert(is_same<apply<if_<_1, Then, Else>, true_>::type, Then>::value, "");

static_assert(is_same<if_<false_, Then, Else>::type, Else>::value, "");
static_assert(is_same<apply<if_<_1, Then, Else>, false_>::type, Else>::value, "");


// if<Cond, Then>::else_if<Cond, Then, Else>
static_assert(is_same<
    if_<false_, int>::else_if<true_, char, float>::type,
    char
>::value, "");
static_assert(is_same<
    apply<if_<_1, int>::else_if<_2, char, float>, false_, true_>::type,
    char
>::value, "");

static_assert(is_same<
    if_<false_, int>::else_if<false_, char, float>::type,
    float
>::value, "");
static_assert(is_same<
    apply<if_<_1, int>::else_if<_2, char, float>, false_, false_>::type,
    float
>::value, "");

static_assert(is_same<
    if_<true_, int>::else_if<false_, char, float>::type,
    int
>::value, "");
static_assert(is_same<
    apply<if_<_1, int>::else_if<_2, char, float>, true_, false_>::type,
    int
>::value, "");


// nested else_if's
static_assert(is_same<
    if_<true_,      struct _if>::
    else_if<false_, struct _else_if1>::
    else_if<false_, struct _else_if2>::
    else_<          struct _else>::type, struct _if
>::value, "");
static_assert(is_same<
    if_<false_,     struct _if>::
    else_if<false_, struct _else_if1>::
    else_if<false_, struct _else_if2>::
    else_if<true_,  struct _else_if3>::
    else_<          struct _else>::type, struct _else_if3
>::value, "");
static_assert(is_same<
    if_<false_,     struct _if>::
    else_if<true_,  struct _else_if1>::
    else_if<false_, struct _else_if2>::
    else_if<true_,  struct _else_if3>::
    else_<          struct _else>::type, struct _else_if1
>::value, "");


int main() { }
