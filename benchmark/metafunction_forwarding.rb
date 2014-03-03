#!/usr/bin/env ruby

##############################################################################
# Comparison between metafunction forwarding and nested type propagation.
##############################################################################


BENCHMARK_CODE=<<-END_OF_BENCHMARK

<% if opts[:forwarding] %>

    template <unsigned i>
    struct metafunction
        : metafunction<i - 1>
    { };

    template <>
    struct metafunction<0> { struct type; };

<% elsif opts[:nested_type] %>

    template <unsigned i>
    struct metafunction {
        using type = typename metafunction<i - 1>::type;
    };

    template <>
    struct metafunction<0> { struct type; };

<% end %>

template struct metafunction<   <%= opts[:depth] %>      >;


int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "metafunction forwarding benchmark with #{compiler.name}"
            plot.xlabel     "nesting depth"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:forwarding, :nested_type]
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

