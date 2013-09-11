/*!
 * @file
 * Contains unit tests for `boost::mpl11::arg`.
 */

#include <boost/mpl11/functional/arg.hpp>

#include <boost/mpl11/functional/bind.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;

struct F { template <typename ...Args> struct apply { struct type; }; };
struct a1; struct a2; struct a3; struct a4;

namespace test_with_matching_number_of_arguments {
    static_assert(equal_to<
        bind<F, _1>::apply<a1>::type,
        F::apply<a1>::type
    >::type::value, "");

    static_assert(equal_to<
        bind<F, _1, _2>::apply<a1, a2>::type,
        F::apply<a1, a2>::type
    >::type::value, "");

    static_assert(equal_to<
        bind<F, _1, _3, _2>::apply<a1, a2, a3>::type,
        F::apply<a1, a3, a2>::type
    >::type::value, "");
}

namespace test_with_excess_arguments_when_applying {
    static_assert(equal_to<
        bind<F, _1>::apply<a1, a2>::type,
        F::apply<a1>::type
    >::type::value, "");

    static_assert(equal_to<
        bind<F, _2, _1>::apply<a1, a2, a3>::type,
        F::apply<a2, a1>::type
    >::type::value, "");
}

namespace test_with_gap_between_arguments {
    static_assert(equal_to<
        bind<F, _2>::apply<a1, a2>::type,
        F::apply<a2>::type
    >::type::value, "");

    static_assert(equal_to<
        bind<F, _2, _4>::apply<a1, a2, a3, a4>::type,
        F::apply<a2, a4>::type
    >::type::value, "");
}


int main() { }
