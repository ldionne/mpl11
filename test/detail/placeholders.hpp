#ifndef BOOST_MPL11_TEST_PLACEHOLDERS_HPP
#define BOOST_MPL11_TEST_PLACEHOLDERS_HPP

#include <boost/mpl11/fwd/lambda.hpp>


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
    struct lambda<test::placeholder::variadic<T...>>
        : test::placeholder::variadic<T...>
    {
        static constexpr bool is_multivalued = false;
        static constexpr bool triggers_recursive_eval = true;
    };

    template <typename T>
    struct lambda<test::placeholder::unary<T>>
        : test::placeholder::unary<T>
    {
        static constexpr bool is_multivalued = false;
        static constexpr bool triggers_recursive_eval = true;
    };

    template <typename T, typename U>
    struct lambda<test::placeholder::binary<T, U>>
        : test::placeholder::binary<T, U>
    {
        static constexpr bool is_multivalued = false;
        static constexpr bool triggers_recursive_eval = true;
    };

    template <>
    struct lambda<test::placeholder::non_template>
        : test::placeholder::non_template
    {
        static constexpr bool is_multivalued = false;
        static constexpr bool triggers_recursive_eval = true;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_PLACEHOLDERS_HPP
