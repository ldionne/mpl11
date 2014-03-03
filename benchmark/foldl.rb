#!/usr/bin/env ruby

##############################################################################
# Comparison between different implementations of a left fold.
##############################################################################


BENCHMARK_CODE=<<-END_OF_BENCHMARK

<% xs = (0..opts[:n_elements]).collect{ |i| 'x<' + i.to_s + '>' } %>

<% if opts[:mpl11] or opts[:fair] %>
    #include <boost/mpl11/list.hpp>
<% end %>

<% if opts[:mpl] or opts[:fair] %>
    #include <boost/mpl/fold.hpp>
    #include <%= "<boost/mpl/vector/vector" + round_up(xs.length, 1).to_s + ".hpp>" %>
<% end %>


template <unsigned>
struct x;

struct state;

struct f {
    using type = f;

    template <typename, typename>
    struct apply {
        struct type;
    };
};


<% if opts[:mpl] %>

    using dataset = boost::mpl:: <%= "vector" + xs.length.to_s + '<' + xs.join(',') + '>' %>;
    using Go = boost::mpl::fold<dataset, state, f>::type;

<% elsif opts[:mpl11] %>

    using dataset = boost::mpl11::list<     <%= xs.join(',') %>   >;
    using Go = boost::mpl11::foldl<f, state, dataset>::type;

<% elsif opts[:aliases] %>

    template <bool done>
    struct until {
        template <typename f, typename state, typename head, typename ...tail>
        using apply =
            typename until<(sizeof...(tail) == 0)>::
            template apply<f,
                typename f::template apply<state, head>::type, tail...
            >;
    };

    template <>
    struct until<true> {
        template <typename f, typename state>
        struct apply {
            using type = state;
        };
    };

    template <typename f, typename state, typename ...xs>
    struct foldl
        : until<sizeof...(xs) == 0>::template apply<f, state, xs...>
    { };

    using Go = foldl<f, state,  <%= xs.join(',') %>     >::type;

<% elsif opts[:standard_recursion] %>

    template <typename f, typename state, typename ...xs>
    struct foldl;

    template <typename f, typename state>
    struct foldl<f, state> {
        using type = state;
    };

    template <typename f, typename state, typename head, typename ...tail>
    struct foldl<f, state, head, tail...>
        : foldl<f, typename f::template apply<state, head>::type, tail...>
    { };

    using Go = foldl<f, state,  <%= xs.join(',') %>     >::type;

<% end %>

int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "left fold benchmark with #{compiler.name}"
            plot.xlabel     "number of folded elements"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:mpl11, :mpl, :aliases, :standard_recursion]
                points = generate_points(0..10) { |n|
                    opts[:n_elements] = n
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
