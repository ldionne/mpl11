#ifndef BOOST_MPL11_TEST_FUNCTIONAL_PLACEHOLDERS_HPP
#define BOOST_MPL11_TEST_FUNCTIONAL_PLACEHOLDERS_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/functional/is_placeholder.hpp>


struct placeholder {
    template <typename ...>
    struct variadic {
        template <typename ...>
        struct apply { struct type; };
    };

    template <typename> struct unary {
        template <typename ...>
        struct apply { struct type; };
    };

    template <typename, typename>
    struct binary {
        template <typename ...>
        struct apply { struct type; };
    };

    struct non_template {
        template <typename ...>
        struct apply { struct type; };
    };
};

namespace boost { namespace mpl11 {
    template <typename ...T>
    struct is_placeholder<placeholder::variadic<T...>>
        : true_
    { };

    template <typename T>
    struct is_placeholder<placeholder::unary<T>>
        : true_
    { };

    template <typename T, typename U>
    struct is_placeholder<placeholder::binary<T, U>>
        : true_
    { };

    template <>
    struct is_placeholder<placeholder::non_template>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_FUNCTIONAL_PLACEHOLDERS_HPP
