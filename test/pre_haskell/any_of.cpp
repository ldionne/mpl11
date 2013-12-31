/*!
 * @file
 * Contains unit tests for `boost::mpl11::any_of`.
 */

#include <boost/mpl11/any_of.hpp>

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

template <typename Container>
struct test_one {
    template <typename ...T>
    using container = apply_t<new_<Container>, vector<T...>>;

    // specify always false predicate
    static_assert(!any_of<
        container<>,
        always<false_>
    >::value, "");

    static_assert(!any_of<
        container<true_>,
        always<false_>
    >::value, "");

    static_assert(!any_of<
        container<true_, true_>,
        always<false_>
    >::value, "");


    // specify always true predicate
    static_assert(!any_of<
        container<>,
        always<true_>
    >::value, "");

    static_assert(any_of<
        container<false_>,
        always<true_>
    >::value, "");

    static_assert(any_of<
        container<false_, false_>,
        always<true_>
    >::value, "");


    template <typename T>
    using same_as = partial<quote<is_same>, T>;

    // specify a sometimes-true predicate
    static_assert(!any_of<
        container<>,
        same_as<struct x>
    >::value, "");

    static_assert(any_of<
        container<struct x>,
        same_as<struct x>
    >::value, "");

    static_assert(!any_of<
        container<struct y>,
        same_as<struct x>
    >::value, "");

    static_assert(any_of<
        container<struct x, struct y>,
        same_as<struct x>
    >::value, "");

    static_assert(any_of<
        container<struct y, struct x>,
        same_as<struct x>
    >::value, "");

    static_assert(any_of<
        container<struct x, struct x>,
        same_as<struct x>
    >::value, "");


    // unspecified predicate
    static_assert(!any_of<
        container<>
    >::value, "");

    static_assert(any_of<
        container<true_>
    >::value, "");

    static_assert(any_of<
        container<true_, true_>
    >::value, "");

    static_assert(!any_of<
        container<false_>
    >::value, "");

    static_assert(any_of<
        container<false_, true_>
    >::value, "");

    static_assert(any_of<
        container<false_, false_, false_, true_>
    >::value, "");
};

struct test_all
    : test_one<vector<>>
{ };


int main() { }
