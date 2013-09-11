/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::none_of`.
 */

#include <boost/mpl11/algorithm/none_of.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/functional/always.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;
using algorithm::none_of;
using container::vector;


namespace specified_predicate {
    static_assert(none_of<
        vector<>,
        always<true_>
    >::type::value, "");

    static_assert(none_of<
        vector<true_, true_>,
        always<false_>
    >::type::value, "");

    static_assert(!none_of<
        vector<float, int, char>,
        equal_to<char, _1>
    >::type::value, "");

    static_assert(none_of<
        vector<float, int, char>,
        equal_to<void, _1>
    >::type::value, "");

    static_assert(none_of<
        vector<false_, false_>,
        _1
    >::type::value, "");

    static_assert(!none_of<
        vector<false_, true_>,
        _1
    >::type::value, "");
}

namespace unspecified_predicate {
    static_assert(none_of<
        vector<>
    >::type::value, "");

    static_assert(none_of<
        vector<false_>
    >::type::value, "");

    static_assert(none_of<
        vector<false_, false_>
    >::type::value, "");

    static_assert(!none_of<
        vector<true_>
    >::type::value, "");

    static_assert(!none_of<
        vector<true_, true_>
    >::type::value, "");

    static_assert(!none_of<
        vector<false_, true_, false_>
    >::type::value, "");
}


int main() { }
