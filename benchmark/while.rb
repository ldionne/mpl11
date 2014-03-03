#!/usr/bin/env ruby

##############################################################################
# Comparison between using aliases and normal templates for a `while_`
# implementation.
##############################################################################


BENCHMARK_CODE=<<-END_OF_BENCHMARK

<% if opts[:aliases] %>

    template <bool Continue>
    struct while_impl {
        template <typename Pred, typename F, typename PrevState, typename State = typename F::template apply<PrevState>::type>
        using apply = typename while_impl<Pred::template apply<State>::value>::
                      template apply<Pred, F, State>;
    };

    template <>
    struct while_impl<false> {
        template <typename Pred, typename F, typename State>
        struct apply {
            using type = State;
        };
    };

    template <typename Pred, typename F, typename State>
    using while_ = typename while_impl<Pred::template apply<State>::value>::
                   template apply<Pred, F, State>;

<% elsif opts[:standard_recursion] %>

    template <typename Pred, typename F, typename State, bool = Pred::template apply<State>::value>
    struct while_;

    template <typename Pred, typename F, typename State>
    struct while_<Pred, F, State, true>
        : while_<Pred, F, typename F::template apply<State>::type>
    { };

    template <typename Pred, typename F, typename State>
    struct while_<Pred, F, State, false> {
        using type = State;
    };

<% end %>

template <typename T, typename U>
struct is_same { static constexpr bool value = false; };

template <typename T>
struct is_same<T, T> { static constexpr bool value = true; };

template <int> struct x;

struct increment {
    template <typename X>
    struct apply;

    template <int i>
    struct apply<x<i>> {
        using type = x<i+1>;
    };
};

template <typename X>
struct different_from {
    template <typename, typename = void>
    struct apply { static constexpr bool value = true; };

    template <typename Dummy>
    struct apply<X, Dummy> { static constexpr bool value = false; };
};

template <typename X>
struct test_until {
    static_assert(is_same<
        typename while_<different_from<X>, increment, x<0>>::type,
        X
    >::value, "");
};

struct test_all :
    test_until<x<0>>,
    test_until<x<1>>,
    test_until<x<2>>,
    test_until<x<3>>,
    test_until<x<4>>
{ };

using Go = while_<different_from<x<     <%= opts[:depth] %>     >>, increment, x<0>>::type;

/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null while.cpp -ftemplate-depth=1010
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null while.cpp -ftemplate-depth=1010
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null while.cpp -ftemplate-depth=1010

Commands were ran 5 times and the average was taken.


                     | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131124 (experimental) |
----------------------------------------------------------------------------------------------
USE_ALIASES          |    0.17s   |         0.09s        |               0.17s               |
USE_NORMAL_RECURSION |    0.18s   |         0.09s        |               0.33s               |

*/

int main() { }

END_OF_BENCHMARK



require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "while benchmark with #{compiler.name}"
            plot.xlabel     "depth of while"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:aliases, :standard_recursion]
                points = generate_points(0..10) { |n|
                    opts[:depth] = n
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
