/*!
 * @file
 * This file contains compile-time unit tests for
 * `boost::mpl11::detail::nested_apply`.
 */

#include <boost/mpl11/detail/nested_apply.hpp>
#include <boost/mpl11/is_same.hpp>


struct non_template_apply { struct apply; };
struct template_apply { template <typename ...> struct apply; };

using namespace boost::mpl11;
using boost::mpl11::detail::nested_apply;

static_assert(is_same<
    nested_apply<non_template_apply>::type,
    non_template_apply::apply
>::value, "");


static_assert(is_same<
    nested_apply<template_apply>::type,
    template_apply::apply<>
>::value, "");

static_assert(is_same<
    nested_apply<template_apply, struct a0>::type,
    template_apply::apply<struct a0>
>::value, "");

static_assert(is_same<
    nested_apply<template_apply, struct a0, struct a1>::type,
    template_apply::apply<struct a0, struct a1>
>::value, "");


int main() { }
