/*!
 * @file
 * Contains unit tests for `boost::mpl11::cons`.
 */

#include <boost/mpl11/cons.hpp>

#include <boost/mpl11/list.hpp>
#include "sequence_test.hpp"


using namespace mpl11_test;
using namespace boost::mpl11;

template <int> struct x;

template <int Head, int ...Tail>
struct test_cons :
    forward_sequence_test<      cons_t<x<Head>, list<x<Tail>...>>, x<Head>, x<Tail>...>,
    finite_sequence_test<       cons_t<x<Head>, list<x<Tail>...>>, x<Head>, x<Tail>...>,
    bidirectional_sequence_test<cons_t<x<Head>, list<x<Tail>...>>, x<Head>, x<Tail>...>,
    random_access_sequence_test<cons_t<x<Head>, list<x<Tail>...>>, x<Head>, x<Tail>...>
{ };

struct tests :
    test_cons<0>,
    test_cons<0, 1>,
    test_cons<0, 1, 2>,
    test_cons<0, 1, 2, 3>,
    test_cons<0, 1, 2, 3, 4>
{ };


int main() { }
