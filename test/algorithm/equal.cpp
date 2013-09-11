/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::equal`.
 */

#include <boost/mpl11/algorithm/equal.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/functional/always.hpp>


using namespace boost::mpl11;
using algorithm::equal;
using container::vector;


namespace without_predicate {
    namespace diff_size {
        static_assert(!equal<
            vector<int>, vector<>
        >::type::value, "");

        static_assert(!equal<
            vector<int>, vector<int, int>
        >::type::value, "");
    }

    static_assert(equal<
        vector<>, vector<>
    >::type::value, "");

    static_assert(equal<
        vector<int>, vector<int>
    >::type::value, "");

    static_assert(equal<
        vector<int, float>, vector<int, float>
    >::type::value, "");

    static_assert(!equal<
        vector<float, int>, vector<int, float>
    >::type::value, "");
}

namespace with_predicate {
    namespace diff_size {
        static_assert(!equal<
            vector<int>, vector<>, always<true_>
        >::type::value, "");

        static_assert(!equal<
            vector<int>, vector<int, int>, always<true_>
        >::type::value, "");
    }

    static_assert(equal<
        vector<>, vector<>, always<true_>
    >::type::value, "");

    static_assert(equal<
        vector<int, int>, vector<int, int>, always<true_>
    >::type::value, "");

    static_assert(equal<
        vector<float, int>, vector<int, float>, always<true_>
    >::type::value, "");
}


int main() { }
