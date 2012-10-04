/**
 * This file defines unit tests for the @em while metafunction.
 */

#include <mpl11/while.hpp>

#include <cstddef>
#include <type_traits>


using namespace mpl11;

template <std::size_t N>
struct less_than {
    template <typename> struct apply;

    template <std::size_t i>
    struct apply<std::integral_constant<std::size_t, i>>
        : std::integral_constant<bool, i < N> { };
};

struct increment {
    template <typename> struct apply;

    template <std::size_t i>
    struct apply<std::integral_constant<std::size_t, i>>
        : std::integral_constant<std::size_t, i + 1> { };
};

static_assert(std::is_same<
                while_<less_than<10>,
                    increment,
                    std::integral_constant<std::size_t, 0>
                >::type,
                std::integral_constant<std::size_t, 10>
              >::value, "");
