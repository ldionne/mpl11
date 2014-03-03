#!/usr/bin/env ruby

##############################################################################
# Comparison of the cost of mentioning a template versus instantiating it.
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
INSTANTIATE          |    0.47s   |         0.22s        |               0.44s               |
MENTION_ONLY         |    0.24s   |         0.12s        |               0.14s               |

20000 instantiations |
----------------------------------------------------------------------------------------------
INSTANTIATE          |    0.92s   |         0.43s        |               0.85s               |
MENTION_ONLY         |    0.46s   |         0.23s        |               0.26s               |

*/


template <int>
struct x { };

<% if opts[:instantiate] %>

    <% for i in 0..opts[:n] %>
        template struct x<  <%= i %>    >;
    <% end %>

<% elsif opts[:mention] %>

    <% for i in 0..opts[:n] %>
        using <%= 'x' + i.to_s %> = x<   <%= i %>    >;
    <% end %>

<% end %>

int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "mention vs instantiating templates with #{compiler.name}"
            plot.xlabel     "number of templates"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:mention, :instantiate]
                points = generate_points(1..10) { |n|
                    opts[:n] = n
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
