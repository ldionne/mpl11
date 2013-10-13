/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::find`.
 */

#include <boost/mpl11/find.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/vector.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>


using namespace boost::mpl11;
using algorithm::find;
using container::vector;

template <typename Sequence, int I>
using iter_at = typename algorithm::advance_c<
    typename begin<Sequence>::type, I
>::type;

static_assert(equal_to<
    find<vector<>, struct anything>::type,
    end<vector<>>::type
>::type::value, "");

static_assert(equal_to<
    find<vector<int>, struct anything>::type,
    end<vector<int>>::type
>::type::value, "");

static_assert(equal_to<
    find<vector<float, int>, struct anything>::type,
    end<vector<float, int>>::type
>::type::value, "");

static_assert(equal_to<
    find<vector<float, int>, int>::type,
    iter_at<vector<float, int>, 1>
>::type::value, "");

static_assert(equal_to<
    find<vector<float, int, int>, int>::type,
    iter_at<vector<float, int, int>, 1>
>::type::value, "");


int main() { }
