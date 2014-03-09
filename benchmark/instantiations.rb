#!/usr/bin/env ruby

##############################################################################
# Comparison between different ways of instantiating the same
# number of templates
##############################################################################


BENCHMARK_CODE=<<-END_OF_BENCHMARK

<% if opts[:flat] %>

    template <unsigned i>
    struct metafunction { struct type; };

    <% for i in 0.upto(opts[:instantiations]) %>
        template struct metafunction<   <%= i %>    >;
    <% end %>

<% elsif opts[:recursive] %>

    template <unsigned i>
    struct metafunction
        : metafunction<i - 1>
    { };

    template <>
    struct metafunction<0> { struct type; };

    template struct metafunction<   <%= opts[:instantiations] %>    >;

<% end %>


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

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts_)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "instantiation of templates with #{compiler.name}"
            plot.xlabel     "number of instantiations"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:flat, :recursive]
                opts = opts_.clone
                opts[curve] = true
                points = generate_points((0..10_000).step 1_000) { |n|
                    opts[:instantiations] = n
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
