/*!
 * @file
 * Contains unit tests for `boost::mpl11::on`.
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

template <typename...> struct e;
template <typename>    struct f;
template <typename>    struct g;
template <typename>    struct h;

struct x { struct type; };
struct y { struct type; };
struct z { struct type; };

template <typename E, typename F, typename G, typename H>
struct test_on {
    static_assert(std_is_same<
        typename on<E>::type::template apply<>::type,
        e<>
    >::value, "");

    static_assert(std_is_same<
        typename on<E, F>::type::template apply<x>::type,
        e<f<x::type>>
    >::value, "");

    static_assert(std_is_same<
        typename on<E, F, G>::type::template apply<x, y>::type,
        e<f<x::type>, g<y::type>>
    >::value, "");

    static_assert(std_is_same<
        typename on<E, F, G, H>::type::template apply<x, y, z>::type,
        e<f<x::type>, g<y::type>, h<z::type>>
    >::value, "");
};

template <template <typename ...> class f>
using quoted = quote<call<f>::type::template apply>;

struct tests :
    test_on<call<e>, call<f>, call<g>, call<h>>,

    // test specialization for quote<>
    test_on<quoted<e>, quoted<f>, quoted<g>, quoted<h>>
{ };


int main() { }
