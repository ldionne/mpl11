/*!
 * @file
 * Comparison between different ways of instantiating the same number
 * of templates.
 */

template <unsigned... I>
struct index_sequence;

template <typename Left, typename Right>
struct concat_indices;

template <unsigned... Left, unsigned... Right>
struct concat_indices<index_sequence<Left...>, index_sequence<Right...>> {
    using type = index_sequence<Left..., (sizeof...(Left) + Right)...>;
};

template <unsigned N>
struct make_index_sequence
    : concat_indices<
        typename make_index_sequence<N / 2>::type,
        typename make_index_sequence<N - N / 2>::type
    >
{ };

template <> struct make_index_sequence<0> { using type = index_sequence<>; };
template <> struct make_index_sequence<1> { using type = index_sequence<0>; };
template <> struct make_index_sequence<2> { using type = index_sequence<0, 1>; };
template struct make_index_sequence<10000>;


#define MAP_OVER_PARAMETER_PACK
// #define INSTANTIATE_LINEARLY
static constexpr unsigned NUMBER_OF_INSTANTIATIONS = 2000;

#if defined(MAP_OVER_PARAMETER_PACK)

    template <typename ...> struct pack;
    template <unsigned> struct metafunction { struct type; };

    template <typename Indices>
    struct instantiate_metafunctions;

    template <unsigned ...Indices>
    struct instantiate_metafunctions<index_sequence<Indices...>> {
        using type = pack<typename metafunction<Indices>::type...>;
    };

    template struct instantiate_metafunctions<
        make_index_sequence<NUMBER_OF_INSTANTIATIONS>::type
    >;

#elif defined(INSTANTIATE_LINEARLY)

    template <unsigned i>
    struct metafunction
        : metafunction<i - 1>
    { };

    template <>
    struct metafunction<0> { struct type; };

    template struct metafunction<NUMBER_OF_INSTANTIATIONS>;

#endif


/*
The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null instantiations.cpp -ftemplate-depth=10000
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null instantiations.cpp -ftemplate-depth=10000
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null instantiations.cpp -ftemplate-depth=10000

Commands were ran 5 times and the average was taken.


With MAP_OVER_PARAMETER_PACK:

 number of instantiations | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
---------------------------------------------------------------------------------------------------
         0000             |    0.20s   |         0.08s        |               3.68s               |
         1000             |    0.24s   |         0.10s        |               3.78s               |
         2000             |    0.29s   |         0.12s        |                [1]                |
         3000             |    0.32s   |         0.14s        |                [1]                |
         4000             |    0.37s   |         0.15s        |                [1]                |
         5000             |    0.33s   |         0.13s        |                [1]                |
         6000             |    0.46s   |         0.18s        |                [1]                |
         7000             |    0.51s   |         0.20s        |                [1]                |
         8000             |    0.54s   |         0.22s        |                [1]                |
         9000             |    0.59s   |         0.24s        |                [1]                |

[1] Not benchmarked due to lazyness.


With INSTANTIATE_LINEARLY:

 number of instantiations | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
---------------------------------------------------------------------------------------------------
         0000             |    0.20s   |         0.09s        |               4.68s               |
         1000             |    0.22s   |         0.09s        |                [1]                |
         2000             |   segfault |         0.10s        |                [1]                |
         3000             |   segfault |         0.11s        |                [1]                |
         4000             |   segfault |        segfault      |                [1]                |
         5000             |   segfault |        segfault      |                [1]                |
         6000             |   segfault |        segfault      |                [1]                |
         7000             |   segfault |        segfault      |                [1]                |
         8000             |   segfault |        segfault      |                [1]                |
         9000             |   segfault |        segfault      |                [1]                |

[1] Not benchmarked due to lazyness.

*/


int main() { }
