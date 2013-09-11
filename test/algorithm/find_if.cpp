/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::find_if`.
 */

#include <boost/mpl11/algorithm/find_if.hpp>

#include <boost/mpl11/algorithm/advance.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;
using algorithm::find_if;
using container::vector;

template <typename Sequence, int I>
using iter_at = typename algorithm::advance_c<
    typename intrinsic::begin<Sequence>::type, I
>::type;

static_assert(equal_to<
    find_if<vector<>, always<true_>>::type,
    intrinsic::end<vector<>>::type
>::type::value, "");

static_assert(equal_to<
    find_if<vector<int>, always<false_>>::type,
    intrinsic::end<vector<int>>::type
>::type::value, "");

static_assert(equal_to<
    find_if<vector<int>, always<true_>>::type,
    iter_at<vector<int>, 0>
>::type::value, "");

static_assert(equal_to<
    find_if<vector<true_>, _1>::type,
    iter_at<vector<true_>, 0>
>::type::value, "");

static_assert(equal_to<
    find_if<
        vector<int, float, char>,
        equal_to<_1, char>
    >::type,
    iter_at<vector<int, float, char>, 2>
>::type::value, "");


int main() { }
