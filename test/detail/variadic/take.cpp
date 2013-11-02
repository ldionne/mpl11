/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::variadic::take`.
 */

#include <boost/mpl11/detail/variadic/take.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic/pack.hpp>


using namespace boost::mpl11;
using namespace detail::variadic;
using detail::is_same;

template <int> struct type;
template <int ...i> using pack_c = pack<type<i>...>;

// Script generating the unit test for `take`. See the notice in
// <boost/mpl11/detail/variadic/take.hpp> before changing this.

/*****************************************************************************

#!/usr/bin/env ruby

O1_TAKE = 10

for pack_size in 0..O1_TAKE*3 do
    for n in 0..pack_size do
        # If we're within 5 indices of the begining or end of the
        # pack_size, we generate a static_assert because we'd like
        # to test border cases.
        #
        # We also generate a static_assert if the parity of n does not match
        # that of the current pack_size. This allows us to save half the
        # static_asserts in average making the test lighter to compile, but
        # we still test even AND odd indices because the parity of pack_size
        # is alternating.
        if [n, pack_size - n].min <= 5 or n.even? == pack_size.even? then
            puts <<-END
static_assert(is_same< \
    take<pack_c<#{(0...pack_size).collect.join(', ')}>, #{n}>::type, \
    pack_c<#{(0...n).collect.join(', ')}> \
>::value, "");
            END
        end
    end
end

*****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
// BEGIN GENERATED OUTPUT. DO NOT EDIT!
//////////////////////////////////////////////////////////////////////////////
static_assert(is_same<     take<pack_c<>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22>, 23>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 23>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23>, 24>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 23>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 24>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24>, 25>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 23>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 24>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 25>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>, 26>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 23>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 24>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 25>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 26>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26>, 27>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 23>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 24>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 25>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 26>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 27>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27>, 28>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 7>::type,     pack_c<0, 1, 2, 3, 4, 5, 6> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 9>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 11>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 13>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 15>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 17>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 19>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 21>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 23>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 24>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 25>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 26>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 27>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 28>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28>, 29>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 0>::type,     pack_c<> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 1>::type,     pack_c<0> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 2>::type,     pack_c<0, 1> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 3>::type,     pack_c<0, 1, 2> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 4>::type,     pack_c<0, 1, 2, 3> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 5>::type,     pack_c<0, 1, 2, 3, 4> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 6>::type,     pack_c<0, 1, 2, 3, 4, 5> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 8>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 10>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 12>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 14>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 16>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 18>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 20>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 22>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 24>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 25>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 26>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 27>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 28>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 29>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28> >::value, "");
static_assert(is_same<     take<pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29>, 30>::type,     pack_c<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29> >::value, "");
//////////////////////////////////////////////////////////////////////////////
// END GENERATED OUTPUT
//////////////////////////////////////////////////////////////////////////////


int main() { }
