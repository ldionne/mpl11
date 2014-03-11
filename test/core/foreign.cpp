/*!
 * @file
 * Contains unit tests for `boost::mpl11::Foreign`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct x;
struct y;

/////////////////////////////////
// Test conversion to `Foreign`.
/////////////////////////////////
static_assert(!std_is_same<
    cast<undefined, Foreign>::type::apply<x>::type,
    cast<undefined, Foreign>::type::apply<y>::type
>::value, "");

static_assert(std_is_same<
    datatype<cast<undefined, Foreign>::type::apply<x>::type>::type,
    Foreign
>::value, "");

static_assert(std_is_same<
    cast<Foreign, Foreign>::type::apply<x>::type,
    x
>::value, "");


//////////////////////////////////////////
// Test `common_datatype` specialization.
//////////////////////////////////////////
static_assert(std_is_same<
    common_datatype<Foreign, undefined>::type,
    Foreign
>::value, "");

static_assert(std_is_same<
    common_datatype<undefined, Foreign>::type,
    Foreign
>::value, "");


///////////////////////////////
// Test `Comparable` instance.
///////////////////////////////
template <bool eq, typename ...x>
struct assert_eq {
    static_assert(eq == equal<box<x>...>::value, "");
};

template <bool eq, typename x_, typename y_>
struct assert_eq<eq, x_, y_> {
    using x = box<x_>;
    using y = box<y_>;

    static_assert(eq == equal<x, y>::value, "");
    static_assert(!equal<x, y>::value == not_equal<x, y>::value, "");
};

struct test_comparable_instance :
    assert_eq<true,  x, x>,
    assert_eq<false, x, y>,
    assert_eq<true,  x, x, x>,
    assert_eq<false, x, x, y>,
    assert_eq<false, x, y, undefined>,
    assert_eq<false, y, x, undefined>
{ };


int main() { }
