#!/usr/bin/env ruby

##############################################################################
# Comparison of techniques to implement compile-time extrema computations.
##############################################################################


BENCHMARK_CODE=<<-END_OF_BENCHMARK

template <long a0, long a1, long ...aN>
struct max
    : max<a0, max<a1, aN...>::value>
{ };

template <long a0, long a1>
struct max<a0, a1> {
    static constexpr long value = a0 < a1 ? a1 : a0;
};

<% if opts[:union] %>

    template <long a0, long a1, long a2, long a3, long a4, long a5, long a6>
    union alignas(char) batch_max_impl {
        char _a0[a0+1];
        char _a1[a1+1];
        char _a2[a2+1];
        char _a3[a3+1];
        char _a4[a4+1];
        char _a5[a5+1];
        char _a6[a6+1];
    };

    template <long ...ai>
    using batch_max = max<
        // The maximum of all the positive integers.
        sizeof(batch_max_impl<(ai < 0 ? 0 : ai)...>) - 1,

        // The minimum of all the negative integers.
        -(sizeof(batch_max_impl<(ai < 0 ? -ai : 0)...>) - 1)
    >;

    template <long a0, long a1, long a2, long a3, long a4, long a5, long a6>
    struct max<a0, a1, a2, a3, a4, a5, a6>
        : batch_max<a0, a1, a2, a3, a4, a5, a6>
    { };

    template <
        long a0, long a1, long a2, long a3, long a4, long a5, long a6,
        long a7, long ...aN
    >
    struct max<a0, a1, a2, a3, a4, a5, a6, a7, aN...>
        : max<max<a0, a1, a2, a3, a4, a5, a6>::value, a7, aN...>
    { };

<% end %>

static_assert(max<-1, 0>::value == 0, "");
static_assert(max<-1, 1>::value == 1, "");
static_assert(max<-1, -4>::value == -1, "");

static_assert(max<0, 0>::value == 0, "");
static_assert(max<0, 1>::value == 1, "");
static_assert(max<1, 0>::value == 1, "");
static_assert(max<1, 1>::value == 1, "");

static_assert(max<0, 1, 2>::value == 2, "");
static_assert(max<0, 1, 2, 3>::value == 3, "");
static_assert(max<0, 4, 2, 3>::value == 4, "");
static_assert(max<0, 1, 2, 3, 2, 3>::value == 3, "");

static_assert(
    max<    <%= opts[:ints].join(',') %>    >::value
                    ==
            <%= opts[:ints].max %>
, "");

/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null max_c.cpp -ftemplate-depth=500 -fconstexpr-depth=500
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null max_c.cpp -ftemplate-depth=500 -fconstexpr-depth=500
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null max_c.cpp -ftemplate-depth=500 -fconstexpr-depth=500

Commands were ran 5 times and the average was taken.

Summing up to 1000         | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
-----------------------------------------------------------------------------------------------------
USE_UNION                  |    0.16s    |         0.07s        |               0.11s               |
USE_RECURSIVE_STRUCTS      |    0.33s[1] |         0.15s[1]     |               0.31s               |

[1] Constexpr / template depth modification is required to avoid hitting the limit.

*/

int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "max benchmark with #{compiler.name}"
            plot.xlabel     "number of elements"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:union, :standard_recursion]
                points = generate_points(1..10) { |n|
                    opts[:ints] = (0..n).to_a.shuffle
                    opts[curve] = true
                    compiler.compile_template_string(BENCHMARK_CODE, binding).real
                }

                plot.data << Gnuplot::DataSet.new(points) { |ds|
                    ds.with = "lines"
                    ds.title = curve
                }
            end
        end
    end
end

Main.new(ARGV).run
