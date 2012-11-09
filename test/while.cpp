/**
 * This file defines unit tests for the @em while metafunction.
 */

#include <mpl11/while.hpp>
#include <mpl11/types.hpp>

#include <cstddef>
#include <type_traits>


using namespace mpl11;

template <std::size_t N>
struct less_than {
    template <typename> struct apply;

    template <std::size_t i>
    struct apply<size_t_<i>> : bool_<i < N> { };
};

struct increment {
    template <typename> struct apply;

    template <std::size_t i>
    struct apply<size_t_<i>> : size_t_<i + 1> { };
};

static_assert(std::is_same<
                while_<less_than<10>,
                    increment,
                    size_t_<0>
                >::type,
                size_t_<10>
              >::value, "");
