/*!
 * @file
 * Contains unit tests for `boost::mpl11::always`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct a;

template <typename ...args>
struct test_always {
    static_assert(std_is_same<
        a,
        typename always<box<a>>::type::template apply<args...>::type
    >::value, "");
};

struct tests :
    test_always<undefined>,
    test_always<undefined, undefined>,
    test_always<undefined, undefined, undefined>,
    test_always<undefined, undefined, undefined, undefined>
{ };


int main() { }
