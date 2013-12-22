/*!
 * @file
 * Contains unit tests for `boost::mpl11::transform`.
 */

#include <boost/mpl11/transform.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/container.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <typename ...T>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<T...>
>;

template <typename ...T>
using container = test::wrapper<
    test::minimal_requirements<Container>, vector<T...>
>;

struct f { template <typename ...> struct apply { struct type; }; };

template <typename ...T>
struct test_one {
    using Lazy = transform<sequence<T...>, f>;
    using Eager = transform_t<container<T...>, f>;

    // We use vector to dispatch the equal<> because transform<> is not
    // a DirectionalSequence.
    static_assert(equal<vector<apply_t<f, T>...>, Lazy>::value, "");
    static_assert(equal<vector<apply_t<f, T>...>, Eager>::value, "");

    static_assert(length<Lazy>::value == sizeof...(T), "");
    static_assert(length<Eager>::value == sizeof...(T), "");

    static_assert(is_empty<Lazy>::value == (sizeof...(T) == 0), "");
    static_assert(is_empty<Eager>::value == (sizeof...(T) == 0), "");
};

struct w; struct x; struct y; struct z;
struct test_all :
    test_one<>,
    test_one<w>,
    test_one<w, x>,
    test_one<w, x, y>,
    test_one<w, x, y, z>
{ };


int main() { }
