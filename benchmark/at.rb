#!/usr/bin/env ruby

##############################################################################
# Comparison of techniques to implement access to parameter packs.
##############################################################################

BENCHMARK_CODE=<<-END_OF_BENCHMARK

template <unsigned... I>
struct index_sequence;

template <typename Left, typename Right>
struct concat_indices;

template <unsigned... Left, unsigned... Right>
struct concat_indices<index_sequence<Left...>, index_sequence<Right...>> {
    using type = index_sequence<Left..., (sizeof...(Left) + Right)...>;
};

template <unsigned N>
struct make_index_sequence
    : concat_indices<
        typename make_index_sequence<N / 2>::type,
        typename make_index_sequence<N - N / 2>::type
    >
{ };

template <> struct make_index_sequence<0> { using type = index_sequence<>; };
template <> struct make_index_sequence<1> { using type = index_sequence<0>; };

<% if opts[:fair] %>
    template struct make_index_sequence<    <%= opts[:n] %>     >;
<% end %>


<% if opts[:overload] %>

    template <typename T>
    struct no_decay;

    template <typename Head>
    struct at_impl;

    // ldionne:
    // I first encountered this technique in the mpl11 repository of
    // Dave Abrahams. Thanks!
    template <unsigned ...Head>
    struct at_impl<index_sequence<Head...>> {
        template <typename Nth>
        static Nth apply(decltype((Head, (void*)0))..., no_decay<Nth>*, ...);
    };

    template <unsigned N, typename ...Args>
    struct at {
        using type = decltype(
            at_impl<typename make_index_sequence<N>::type>::apply(
                (no_decay<Args>*)nullptr...
            )
        );
    };

<% elsif opts[:multiple_inheritance] %>

    template <typename T>
    struct no_decay {
        using type = T;
    };

    template <unsigned Index, typename Value>
    struct holder { };

    template <typename Indices, typename ...T>
    struct vector;

    // This is equivalent to the multiple inheritance implementation of the
    // map in map.cpp.
    template <unsigned ...Indices, typename ...T>
    struct vector<index_sequence<Indices...>, T...> : holder<Indices, T>... {
        template <unsigned Index, typename Value>
        static no_decay<Value> at_impl(holder<Index, Value>*);
    };

    template <unsigned N, typename ...Args>
    struct at {
        using Vector = vector<
            typename make_index_sequence<sizeof...(Args)>::type, Args...
        >;
        using type = typename decltype(
            Vector::template at_impl<N>((Vector*)nullptr)
        )::type;
    };

<% end %>

template <unsigned>
struct t;

template <typename T, typename U>
struct is_same { static constexpr bool value = false; };

template <typename T>
struct is_same<T, T> { static constexpr bool value = true; };


static_assert(is_same<at<0, t<0>>::type, t<0>>::value, "");
static_assert(is_same<at<0, t<0>, t<1>>::type, t<0>>::value, "");
static_assert(is_same<at<0, t<0>, t<1>, t<2>>::type, t<0>>::value, "");

static_assert(is_same<at<1, t<0>, t<1>>::type, t<1>>::value, "");
static_assert(is_same<at<1, t<0>, t<1>, t<2>>::type, t<1>>::value, "");
static_assert(is_same<at<1, t<0>, t<1>, t<2>, t<3>>::type, t<1>>::value, "");

static_assert(is_same<at<2, t<0>, t<1>, t<2>>::type, t<2>>::value, "");
static_assert(is_same<at<2, t<0>, t<1>, t<2>, t<3>>::type, t<2>>::value, "");
static_assert(is_same<at<2, t<0>, t<1>, t<2>, t<3>, t<4>>::type, t<2>>::value, "");

<%
    ts = (0..opts[:n]).collect{ |i| "t<" + i.to_s + ">" }.join(', ')
    for i in 0...opts[:n]
%>

    static_assert(is_same<
        at<     <%= i %>, <%= ts %>     >::type,
        t<      <%= i %>                >
    >::value, "");

<% end %>


int main() { }


/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null -c at.cpp
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -c at.cpp
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null -c at.cpp

Commands were ran 5 times and the average was taken.


1 invocation             | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.11s   |         0.xxs        |               0.14s               |
USE_MULTIPLE_INHERITANCE |    0.14s   |         0.xxs        |               0.18s               |

2 invocations            |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.12s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    0.14s   |         0.xxs        |               0.xxs               |

4 invocations            |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.17s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    0.17s   |         0.xxs        |               0.xxs               |

8 invocations            |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.22s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    0.22s   |         0.xxs        |               0.xxs               |

16 invocations           |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.33s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    0.29s   |         0.xxs        |               0.xxs               |

32 invocations           |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    0.55s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    0.45s   |         0.xxs        |               0.xxs               |

64 invocations           |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    1.04s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    0.73s   |         0.xxs        |               0.xxs               |

128 invocations          |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    2.10s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    1.32s   |         0.xxs        |               0.xxs               |

256 invocations          |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |    4.55s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    2.57s   |         0.xxs        |               0.xxs               |

512 invocations          |
--------------------------------------------------------------------------------------------------
USE_OVERLOAD             |   10.79s   |         0.xxs        |               0.xxs               |
USE_MULTIPLE_INHERITANCE |    5.05s   |         0.xxs        |               2.85s               |

*/

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "at benchmark with #{compiler.name}"
            plot.xlabel     "number of elements"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            for curve in [:multiple_inheritance, :overload]
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
