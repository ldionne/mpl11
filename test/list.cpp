/*!
 * @file
 * Contains unit tests for @ref List.
 */

#include <boost/mpl11/list.hpp>

#include <boost/mpl11/integer.hpp>
#include "check_finite_iterable.hpp"


using namespace boost::mpl11;

template <int ...xs>
struct test_list
    : check_finite_iterable<
        list<int_<xs>...>,
        int_<xs>...
    >
    , check_finite_iterable<
        cons<int_<-1>, minimal_iterable<int_<xs>...>>,
        int_<-1>, int_<xs>...
    >
    , check_finite_iterable<
        cons<int_<-1>, list<int_<xs>...>>,
        int_<-1>, int_<xs>...
    >
{ };

struct tests :
      test_list<>
    , test_list<0>
    , test_list<0, 1>
    , test_list<0, 1, 2>
    , test_list<0, 1, 2, 3>
    , test_list<0, 1, 2, 3, 4>
    , test_list<0, 1, 2, 3, 4, 5>
{ };


int main() { }
