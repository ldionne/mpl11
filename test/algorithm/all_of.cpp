/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::all_of`.
 */

#include <boost/mpl11/algorithm/all_of.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;
using algorithm::all_of;
using container::vector;


namespace specified_predicate {
    // always false
    static_assert(all_of<
        vector<>,
        always<false_>
    >::type::value, "");

    static_assert(!all_of<
        vector<true_>,
        always<false_>
    >::type::value, "");

    static_assert(!all_of<
        vector<true_, true_>,
        always<false_>
    >::type::value, "");


    // always true
    static_assert(all_of<
        vector<>,
        always<true_>
    >::type::value, "");

    static_assert(all_of<
        vector<false_>,
        always<true_>
    >::type::value, "");

    static_assert(all_of<
        vector<false_, false_>,
        always<true_>
    >::type::value, "");


    // Try with `PlaceholderExpression`s.
    static_assert(all_of<
        vector<true_, true_>,
        _1
    >::type::value, "");

    static_assert(all_of<
        vector<int, int>,
        equal_to<int, _1>
    >::type::value, "");

    static_assert(!all_of<
        vector<int, float>,
        equal_to<int, _1>
    >::type::value, "");
}

namespace unspecified_predicate {
    static_assert(all_of<
        vector<>
    >::type::value, "");

    static_assert(all_of<
        vector<true_>
    >::type::value, "");

    static_assert(all_of<
        vector<true_, true_>
    >::type::value, "");

    static_assert(!all_of<
        vector<false_>
    >::type::value, "");

    static_assert(!all_of<
        vector<false_, true_>
    >::type::value, "");

    static_assert(!all_of<
        vector<true_, true_, true_, false_>
    >::type::value, "");
}


int main() { }
