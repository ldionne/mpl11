/*!
 * @file
 * Contains unit tests for `boost::mpl11::FrontExtensibleContainer`.
 */

#include <boost/mpl11/front_extensible_container.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <typename ...T>
using container = test::wrapper<
    test::minimal_requirements<FrontExtensibleContainer>,
    vector<T...>
>;

struct x; struct y; struct z;

// new_
static_assert(is_same<
    apply<new_<container<>>>::type, container<>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, x>::type, container<x>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, x, y>::type, container<x, y>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, x, y, z>::type, container<x, y, z>
>::value, "");


int main() { }
