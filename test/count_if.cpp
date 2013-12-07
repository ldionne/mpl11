/*!
 * @file
 * Contains unit tests for `boost::mpl11::count_if`.
 */

#include <boost/mpl11/count_if.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct x; struct y; struct z;

template <typename Container>
struct test_one {
    template <typename ...T>
    using sequence = apply_t<new_<Container>, vector<T...>>;

    static_assert(count_if<sequence<>, always<true_>>::value == 0, "");
    static_assert(count_if<sequence<x>, always<true_>>::value == 1, "");
    static_assert(count_if<sequence<x, y>, always<true_>>::value == 2, "");
    static_assert(count_if<sequence<x, y, z>, always<true_>>::value == 3, "");

    template <typename T>
    using same_as = partial<quote<is_same>, T>;
    static_assert(count_if<sequence<x>, same_as<x>>::value == 1, "");
    static_assert(count_if<sequence<x, x>, same_as<x>>::value == 2, "");
    static_assert(count_if<sequence<x, x, x>, same_as<x>>::value == 3, "");
    static_assert(count_if<sequence<x, y, x>, same_as<x>>::value == 2, "");
    static_assert(count_if<sequence<x, y, z>, same_as<x>>::value == 1, "");
    static_assert(count_if<sequence<y, y, z>, same_as<x>>::value == 0, "");

    // Make sure the predicate is not evaluated when the sequence is empty.
    static_assert(count_if<
        sequence<>, struct not_a_metafunction
    >::value == 0, "");
};

struct test_all
    : test_one<vector<>>
{ };


int main() { }
