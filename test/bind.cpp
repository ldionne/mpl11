/*!
 * @file
 * This file contains unit tests for `boost::mpl11::bind`.
 */

#include <boost/mpl11/bind.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/has_type.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;
using detail::has_type;

struct F {
    template <typename ...Args>
    struct apply { struct type; };
};

template <typename T>
struct always_
    : always<T>
{ };

namespace boost { namespace mpl11 {
    template <typename T>
    struct is_placeholder<always_<T>>
        : true_
    { };
}} // end namespace boost::mpl11

struct a0; struct a1;
struct ignored1; struct ignored2;

namespace without_placeholders {
    static_assert(is_same<
        apply_wrap<bind<F>>::type,
        apply_wrap<bind<F>, ignored1>::type,
        F::apply<>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, a0>>::type,
        apply_wrap<bind<F, a0>, ignored1>::type,
        F::apply<a0>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, a0, a1>>::type,
        apply_wrap<bind<F, a0, a1>, ignored1>::type,
        F::apply<a0, a1>::type
    >::value, "");
}

namespace with_placeholders {
    static_assert(is_same<
        apply_wrap<bind<F, always_<a0>>>::type,
        F::apply<a0>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, always_<a0>>, ignored1>::type,
        F::apply<a0>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<
            bind<F, always_<a0>, always_<a1>>, ignored1, ignored2
        >::type,
        F::apply<a0, a1>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, always_<always_<a0>>>, ignored1>::type,
        F::apply<always_<a0>>::type
    >::value, "");
}

namespace with_valid_and_invalid_number_of_arguments {
    // Note: The number of arguments we're referring to here is the number
    // of arguments to `bind<>`, since there is no such thing as an invalid
    // number of arguments when applying a `bind<>` expression.

    struct F {
        template <typename SingleArg>
        struct apply { struct type; };
    };

    static_assert(is_same<
        apply_wrap<bind<F, a0>>::type,
        F::apply<a0>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, a0>, ignored1>::type,
        F::apply<a0>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, a0>, ignored1, ignored2>::type,
        F::apply<a0>::type
    >::value, "");

    static_assert(!has_type<
        apply_wrap<bind<F /* missing argument */>>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<bind<F /* missing argument */>, ignored1>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<bind<F /* missing argument */>, ignored1, ignored2>
    >::value, "");
}

namespace nested_binds_are_not_evaluated {
    static_assert(is_same<
        apply_wrap<bind<F, bind<F>>>::type,
        F::apply<bind<F>>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, bind<F>>, ignored1>::type,
        F::apply<bind<F>>::type
    >::value, "");
}

namespace mix_nested_binds_and_placeholders {
    static_assert(is_same<
        apply_wrap<bind<F, always_<a0>, bind<F, a1>>>::type,
        F::apply<a0, bind<F, a1>>::type
    >::value, "");

    static_assert(is_same<
        apply_wrap<bind<F, bind<F, always_<a0>>>>::type,
        F::apply<bind<F, always_<a0>>>::type
    >::value, "");
}


int main() { }
