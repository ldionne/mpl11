#!/usr/bin/env ruby

BENCHMARK_CODE=<<-END_OF_BENCHMARK

<% xs = (0..opts[:n_elements]).collect{ |i| 'x<' + i.to_s + '>' } %>

<% if opts[:mpl11] or opts[:fair] %>
    #include <boost/mpl11/list.hpp>
<% end %>

<% if opts[:mpl] or opts[:fair] %>
    #include <boost/mpl/at.hpp>
    #include <%= "<boost/mpl/vector/vector" + round_up(xs.length, 1).to_s + ".hpp>" %>
<% end %>


template <unsigned>
struct x { struct type; };

template <typename a, typename b>
struct is_same { static constexpr bool value = false; };

template <typename a>
struct is_same<a, a> { static constexpr bool value = true; };

<% if opts[:mpl] %>

    using dataset = boost::mpl:: <%= "vector" + xs.length.to_s + '<' + xs.join(',') + '>' %>;
    static_assert(is_same<
        boost::mpl::at_c<dataset, <%= xs.length - 1 %>>::type,
        x<<%= xs.length - 1 %>>
    >::value, "");

<% elsif opts[:mpl11] %>

    using dataset = boost::mpl11::list<     <%= xs.join(',') %>   >;
    static_assert(is_same<
        boost::mpl11::at_c<<%= xs.length - 1 %>, dataset>::type,
        x<<%= xs.length - 1 %>>::type
    >::value, "");

<% end %>

int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts_)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "at benchmark with #{compiler.name}"
            plot.xlabel     "number of elements"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:mpl11, :mpl]
                opts = opts_.clone
                opts[curve] = true
                points = generate_points(0..50) { |n|
                    opts[:n_elements] = n
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
