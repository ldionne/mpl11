#ifndef BOOST_MPL11_TEST_PLACEHOLDERS_HPP
#define BOOST_MPL11_TEST_PLACEHOLDERS_HPP

#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/is_placeholder.hpp>


namespace boost { namespace mpl11 {
    namespace test {
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
    } // end namespace test

    template <typename ...T>
    struct is_placeholder<test::placeholder::variadic<T...>>
        : true_
    { };

    template <typename T>
    struct is_placeholder<test::placeholder::unary<T>>
        : true_
    { };

    template <typename T, typename U>
    struct is_placeholder<test::placeholder::binary<T, U>>
        : true_
    { };

    template <>
    struct is_placeholder<test::placeholder::non_template>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_PLACEHOLDERS_HPP
