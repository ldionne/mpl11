#!/usr/bin/env ruby

##############################################################################
# Comparison of techniques to implement lookup in compile-time maps.
##############################################################################


BENCHMARK_CODE=<<-END_OF_BENCHMARK

template <typename T, typename U>
struct is_same { static constexpr bool value = false; };

template <typename T>
struct is_same<T, T> { static constexpr bool value = true; };

template <typename T>
struct no_decay {
    using type = T;
};

template <typename First, typename Second>
struct pair;


<% if opts[:multiple_inheritance] %>

    template <typename Pair>
    struct holder { };

    // ldionne:
    // I first encountered this technique in a post by Augustin Bergé on
    // the Boost mailing list. Thanks!
    template <typename ...Pairs>
    struct map : holder<Pairs>... {
    private:
        template <typename Key, typename Value>
        static no_decay<Value> at_key_impl(holder<pair<Key, Value>>*);

    public:
        template <typename Key>
        struct at_key
            : decltype(map::at_key_impl<Key>((map*)nullptr))
        { };
    };

<% elsif opts[:single_inheritance] %>

    template <typename ...Pairs>
    struct map {
        template <typename Key>
        static typename Key::error_not_found at_key_impl(no_decay<Key>*);
    };

    template <typename Key, typename Value, typename ...Rest>
    struct map<pair<Key, Value>, Rest...> : map<Rest...> {
        using map<Rest...>::at_key_impl;
        static no_decay<Value> at_key_impl(no_decay<Key>*);

        template <typename K>
        struct at_key
            : decltype(map::at_key_impl((no_decay<K>*)nullptr))
        { };
    };

<% end %>

template <int> struct k;
template <int> struct v;
template <int Key, int Value> using kv = pair<k<Key>, v<Value>>;

static_assert(is_same<
    map<kv<0, 0>, kv<1, 1>, kv<2, 2>>::at_key<k<0>>::type,
    v<0>
>::value, "");

static_assert(is_same<
    map<kv<0, 0>, kv<1, 1>, kv<2, 2>>::at_key<k<1>>::type,
    v<1>
>::value, "");

static_assert(is_same<
    map<
        <%=
            kvs = (0..opts[:nkeys]).collect { |i|
                'kv<' + i.to_s + ',' + i.to_s + '>'
            }
            kvs.join(', ')
        %>
    >::at_key<
        k<
            <%= opts[:nkeys] %>
        >
    >::type,
    v<
        <%= opts[:nkeys] %>
    >
>::value, "");


int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "compile-time map benchmark with #{compiler.name}"
            plot.xlabel     "number of keys in the map"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:single_inheritance, :multiple_inheritance]
                points = generate_points(0..200) { |nkeys|
                    opts[:nkeys] = nkeys
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
