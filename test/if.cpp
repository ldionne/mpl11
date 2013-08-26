/*!
 * @file
 * This file contains unit tests for `boost::mpl11::if_`.
 */

#include <boost/mpl11/if.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/has_type.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;
using detail::has_type;

struct Then;
struct Else;

// if<Cond> (same as enable_if<Cond>)
static_assert(is_same<if_<true_>::type, void>::value, "");
static_assert(!has_type<if_<false_>>::value, "");


// if<Cond, Then> (same as enable_if<Cond, Then>)
static_assert(is_same<if_<true_, Then>::type, Then>::value, "");
static_assert(!has_type<if_<false_, Then>>::value, "");


// if<Cond>::then<Then> (same as if<Cond, Then>)
static_assert(is_same<if_<true_>::then<Then>::type, Then>::value, "");
static_assert(!has_type<if_<false_>::then<Then>>::value, "");


// if<Cond, Then, Else>
static_assert(is_same<if_<true_, Then, Else>::type, Then>::value, "");
static_assert(is_same<if_<false_, Then, Else>::type, Else>::value, "");


// if<Cond>::then<Then>::else<Else>
static_assert(is_same<
    if_<true_>::then<Then>::
    else_<Else>::type,
    Then
>::value, "");
static_assert(is_same<
    if_<false_>::then<Then>::
    else_<Else>::type,
    Else
>::value, "");


// if<Cond>::then<Then>::else_if<Cond, Else>
static_assert(is_same<
    if_<false_>::then<Then>::
    else_if<true_, Else>::type,
    Else
>::value, "");
static_assert(is_same<
    if_<true_>::then<Then>::
    else_if<false_, Else>::type,
    Then
>::value, "");
static_assert(is_same<
    if_<true_>::then<Then>::
    else_if<true_, Else>::type,
    Then
>::value, "");


// if<Cond, Then>::else_if<Cond, Then>
static_assert(is_same<
    if_<false_, Then>::
    else_if<true_, Else>::type,
    Else
>::value, "");
static_assert(is_same<
    if_<true_, Then>::
    else_if<false_, Else>::type,
    Then
>::value, "");
static_assert(is_same<
    if_<true_, Then>::
    else_if<true_, Else>::type,
    Then
>::value, "");


// if<Cond, Then>::else_if<Cond>::then<Else>
static_assert(is_same<
    if_<false_, Then>::
    else_if<true_>::then<Else>::type,
    Else
>::value, "");
static_assert(is_same<
    if_<true_, Then>::
    else_if<false_>::then<Else>::type,
    Then
>::value, "");
static_assert(is_same<
    if_<true_, Then>::
    else_if<true_>::then<Else>::type,
    Then
>::value, "");


// nested else_if's
static_assert(is_same<
    if_<true_, int>::
    else_if<false_, float>::
    else_if<false_, char>::type, int
>::value, "");
static_assert(is_same<
    if_<false_, int>::
    else_if<false_, float>::
    else_if<false_, char>::
    else_if<true_, void>::type, void
>::value, "");
static_assert(is_same<
    if_<false_, int>::
    else_if<true_, float>::
    else_if<false_, char>::
    else_if<true_, void>::type, float
>::value, "");


// nested else_if's and then
static_assert(is_same<
    if_<false_>::then<int>::
    else_if<false_>::then<float>::
    else_if<true_>::then<void>::type, void
>::value, "");


// enable_if behavior with else_if's
static_assert(!has_type<
    if_<false_, int>::
    else_if<false_, float>::
    else_if<false_, char>
>::value, "");


int main() { }
