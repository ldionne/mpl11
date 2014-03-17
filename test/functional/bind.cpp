/*!
 * @file
 * Contains unit tests for `boost::mpl11::bind`.
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

template <typename...> struct e; using E = call<e>;
template <typename...> struct f; using F = call<f>;
template <typename...> struct g; using G = call<g>;
template <typename...> struct h; using H = call<h>;

struct x { struct type; };
struct y { struct type; };
struct z { struct type; };

template <typename E, typename F, typename G, typename H>
struct test_bind {
    static_assert(std_is_same<
        typename bind<E>::type::template apply<>::type,
        e<>
    >::value, "");

    static_assert(std_is_same<
        typename bind<E, F>::type::template apply<x>::type,
        e<f<x::type>>
    >::value, "");

    static_assert(std_is_same<
        typename bind<E, F, G>::type::template apply<x, y>::type,
        e<f<x::type, y::type>, g<x::type, y::type>>
    >::value, "");

    static_assert(std_is_same<
        typename bind<E, F, G, H>::type::template apply<x, y, z>::type,
        e<
            f<x::type, y::type, z::type>,
            g<x::type, y::type, z::type>,
            h<x::type, y::type, z::type>
        >
    >::value, "");
};

template <template <typename ...> class f>
using lifted = lift<call<f>::type::template apply>;

struct tests :
    test_bind<call<e>, call<f>, call<g>, call<h>>,

    // test specialization for lift<>
    test_bind<lifted<e>, lifted<f>, lifted<g>, lifted<h>>
{ };


int main() { }
