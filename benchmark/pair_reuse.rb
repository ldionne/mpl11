#!/usr/bin/env ruby

##############################################################################
# Comparison of reusing a template versus using a new one more specialized
# for the task at hand.
##############################################################################

BENCHMARK_CODE=<<-END_OF_BENCHMARK

/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null -c mention_vs_instantiate.cpp
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -c mention_vs_instantiate.cpp
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -c mention_vs_instantiate.cpp

Commands were ran 5 times and the average was taken.

10000 instantiations | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
----------------------------------------------------------------------------------------------
REUSE_PAIR           |    0.79s   |         0.39s        |               0.61s               |
USE_SPECIALIZED_PAIR |    0.67s   |         0.32s        |               0.55s               |

20000 instantiations |
----------------------------------------------------------------------------------------------
REUSE_PAIR           |    0.xxs   |         0.xxs        |               0.xxs               |
USE_SPECIALIZED_PAIR |    0.xxs   |         0.xxs        |               0.xxs               |

*/

template <int>
struct x;

<% if opts[:reuse] %>

    template <int>
    struct int_;

    template <typename, typename>
    struct pair { };

    <% for i in 0..opts[:elements] %>
        template struct pair<
            int_<   <%= i %>    >,
            x<      <%= i %>    >
        >;
    <% end %>

<% elsif opts[:specialized] %>

    template <int, typename>
    struct pair { };

    <% for i in 0..opts[:elements] %>
        template struct pair<
                    <%= i %>     ,
            x<      <%= i %>    >
        >;
    <% end %>

<% end %>

int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts_)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "pair reuse benchmark with #{compiler.name}"
            plot.xlabel     "number of instantiated pairs"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:specialized, :reuse]
                opts = opts_.clone
                opts[curve] = true
                points = generate_points(1..10) { |n|
                    opts[:elements] = n
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
