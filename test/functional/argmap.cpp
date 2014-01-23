/*!
 * @file
 * Contains unit tests for `boost::mpl11::argmap`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <template <typename ...> class f>
struct call {
    struct mf {
        template <typename ...x>
        struct apply { using type = f<typename x::type...>; };
    };
    using type = mf;
};

template <typename ...> struct f; using F = call<f>;
template <typename ...> struct g; using G = call<g>;

struct x { struct type; };
struct y { struct type; };
struct z { struct type; };

static_assert(std_is_same<
    argmap<F, G>::type::apply<>::type,
    f<>
>::value, "");

static_assert(std_is_same<
    argmap<F, G>::type::apply<x>::type,
    f<g<x::type>>
>::value, "");

static_assert(std_is_same<
    argmap<F, G>::type::apply<x, y>::type,
    f<g<x::type>, g<y::type>>
>::value, "");

static_assert(std_is_same<
    argmap<F, G>::type::apply<x, y, z>::type,
    f<g<x::type>, g<y::type>, g<z::type>>
>::value, "");


int main() { }
