/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::find`.
 */

#include <boost/mpl11/algorithm/find.hpp>

#include <boost/mpl11/algorithm/advance.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>


using namespace boost::mpl11;
using algorithm::find;
using detail::is_same;
using container::vector;

template <typename Sequence, int I>
using iter_at = typename algorithm::advance_c<
    typename intrinsic::begin<Sequence>::type, I
>::type;

static_assert(is_same<
    find<vector<>, struct anything>::type,
    intrinsic::end<vector<>>::type
>::value, "");

static_assert(is_same<
    find<vector<int>, struct anything>::type,
    intrinsic::end<vector<int>>::type
>::value, "");

static_assert(is_same<
    find<vector<float, int>, struct anything>::type,
    intrinsic::end<vector<float, int>>::type
>::value, "");

static_assert(is_same<
    find<vector<float, int>, int>::type,
    iter_at<vector<float, int>, 1>
>::value, "");

static_assert(is_same<
    find<vector<float, int, int>, int>::type,
    iter_at<vector<float, int, int>, 1>
>::value, "");


int main() { }
