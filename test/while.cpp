/**
 * This file defines unit tests for the @em while metafunction.
 */

#include <mpl11/while.hpp>
#include <mpl11/bool.hpp>
#include <mpl11/size_t.hpp>

#include <cstddef>
#include <type_traits>


using namespace mpl11;

template <std::size_t N>
struct less_than {
    template <typename> struct apply;

    template <std::size_t i>
    struct apply<mpl11::size_t<i>> : bool_<i < N> { };
};

struct increment {
    template <typename> struct apply;

    template <std::size_t i>
    struct apply<mpl11::size_t<i>> : mpl11::size_t<i + 1> { };
};

static_assert(std::is_same<
                while_<less_than<10>,
                    increment,
                    mpl11::size_t<0>
                >::type,
                mpl11::size_t<10>
              >::value, "");
