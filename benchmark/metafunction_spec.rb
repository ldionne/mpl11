#!/usr/bin/env ruby

##############################################################################
# Metafunction instantiations in two cases
# - The metafunction is specialized for different arguments
# - The metafunction uses a nested type of the argument to customize
#   its behavior
##############################################################################


def x(i); 'x' + i.to_s; end

BENCHMARK_CODE=<<-END_OF_BENCHMARK

<% if opts[:full_specialization] %>

    template <typename x>
    struct metafunction;

    <% for i in 0..opts[:nspec] %>
        struct <%= x(i) %>;

        template <>
        struct metafunction<    <%= x(i) %>    > { struct type; };
    <% end %>

<% elsif opts[:nested_type] %>

    template <typename x>
    struct metafunction {
        using type = typename x::type;
    };

    <% for i in 0..opts[:nspec] %>
        struct <%= x(i) %> { struct type; };
    <% end %>

<% end %>

<% for i in 0..opts[:nspec] %>
    template struct metafunction<   <%= x(i) %>     >;
<% end %>

int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts_)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "metafunction_spec benchmark with #{compiler.name}"
            plot.xlabel     "number of specializations"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:full_specialization, :nested_type]
                opts = opts_.clone
                opts[curve] = true
                points = generate_points((0..5_000).step(100)) { |nspec|
                    opts[:nspec] = nspec
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
