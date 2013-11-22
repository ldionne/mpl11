/*!
 * @file
 * Contains unit tests for `boost::mpl11::BackExtensibleContainer`.
 */

#include <boost/mpl11/back_extensible_container.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <typename ...T>
using container = test::wrapper<
    test::minimal_requirements<BackExtensibleContainer>,
    vector<T...>
>;

template <typename ...T>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>,
    vector<T...>
>;

struct x; struct y; struct z;

// new_
static_assert(is_same<
    apply<new_<container<>>, sequence<>>::type, container<>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, sequence<x>>::type, container<x>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, sequence<x, y>>::type, container<x, y>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, sequence<x, y, z>>::type, container<x, y, z>
>::value, "");


int main() { }
