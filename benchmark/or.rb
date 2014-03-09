#!/usr/bin/env ruby


##############################################################################
# Comparison of techniques to implement compile-time logical conjunction.
##############################################################################

BENCHMARK_CODE=<<-END_OF_BENCHMARK

template <bool Condition, typename Then, typename Else>
struct conditional { using type = Then; };

template <typename Then, typename Else>
struct conditional<false, Then, Else> { using type = Else; };

<% if opts[:overload] %>

    template <typename ...T>
    constexpr bool all_pointers(T*...) { return true; }

    template <typename ...T>
    constexpr bool all_pointers(T...) { return false; }

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !all_pointers(
            ((typename conditional<T::value, int, void*>::type)0)...
        );
    };

    template <>
    struct or_<> {
        static constexpr bool value = false;
    };

<% elsif opts[:noexcept] %>

    void allow_expansion(...) noexcept;

    struct non_throwing { non_throwing() noexcept { } };
    struct throwing { throwing() { throw; } };

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !noexcept(
            allow_expansion(
                typename conditional<
                    T::value, throwing, non_throwing
                >::type{}...
            )
        );
    };

<% elsif opts[:linear_constexpr] %>

    // This has horrible performance and we sometimes hit the recursion
    // limit on Clang.
    constexpr bool or_impl() { return false; }

    template <typename ...Tail>
    constexpr bool or_impl(bool head, Tail... tail) {
        return head || or_impl(tail...);
    }

    template <typename ...T>
    struct or_ {
        static constexpr bool value = or_impl(T::value...);
    };

<% elsif opts[:structs] %>

    // Surprisingly (for me), this is better than the above solution using
    // constexpr functions, but it still sucks and we hit the recursion limit
    // on Clang quite easily.
    template <typename ...T>
    struct or_ {
        static constexpr bool value = false;
    };

    template <typename Head, typename ...Tail>
    struct or_<Head, Tail...> {
        static constexpr bool value = Head::value || or_<Tail...>::value;
    };

<% elsif opts[:specialization] %>

    // I don't know why I did not think of this earlier. This is clearly
    // the simplest method and it's also the fastest. lol
    template <typename ...T>
    struct or_ {
        static constexpr bool value = true;
    };

    template <template <bool> class ...Bool>
    struct or_<Bool<false>...> {
        static constexpr bool value = false;
    };

<% elsif opts[:aliases] %>

    template <bool ValueOfLast, bool WeAreDone>
    struct or_impl;

    template <>
    struct or_impl<false, false> {
        template <typename F1, typename ...Fn>
        using apply = typename or_impl<
                        static_cast<bool>(F1::type::value),
                        sizeof...(Fn) == 0
                      >::template apply<Fn...>;
    };

    template <>
    struct or_impl<false, true> {
        template <typename ...Fn>
        using apply = false_;
    };

    template <bool WeAreDone>
    struct or_impl<true, WeAreDone> {
        template <typename ...>
        using apply = true_;
    };

    template <typename ...Fn>
    struct or_
        : or_impl<false, false>::template apply<Fn...>
    { };

    template <>
    struct or_<>
        : false_
    { };

<% elsif opts[:short_circuit_structs] %>

    template <bool b, typename ...c>
    struct or_impl : bool_<b> { };

    template <typename c, typename ...cs>
    struct or_impl<false, c, cs...> : or_impl<c::type::value, cs...> { };

    template <typename ...c>
    struct or_ : or_impl<false, c...> { };

<% end %>

template <bool B>
struct bool_ { static constexpr bool value = B; };

using true_ = bool_<true>;
using false_ = bool_<false>;

static_assert(!or_<>::value, "");

static_assert( or_<true_>::value, "");
static_assert(!or_<false_>::value, "");

static_assert( or_<true_, true_>::value, "");
static_assert( or_<true_, false_>::value, "");
static_assert( or_<false_, true_>::value, "");
static_assert(!or_<false_, false_>::value, "");

static_assert(or_<    <%= opts[:bools].join(',') %>  >::value, "");


/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null or_c.cpp
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null or_c.cpp -ftemplate-depth=500
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null or_c.cpp

Commands were ran 5 times and the average was taken.


                     | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
----------------------------------------------------------------------------------------------
USE_OVERLOAD         |    0.03s   |         0.02s        |               0.04s               |
USE_NOEXCEPT         |    0.04s   |         0.02s        |               0.03s               |
USE_LINEAR_CONSTEXPR |    0.17s   |         0.08s(*)     |               0.20s               |
USE_STRUCTS          |    0.09s   |         0.05s(*)     |               0.07s               |
USE_SPECIALIZATION   |    0.02s   |         0.02s        |               0.03s               |

(*) -ftemplate-depth=500 is required to avoid hitting the recursive template instantiation limit.

*/

int main() { }

END_OF_BENCHMARK

require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, io, opts_)
        Gnuplot::Plot.new(io) do |plot|
            plot.title      "logical or benchmark with #{compiler.name}"
            plot.xlabel     "number of or'ed elements"
            plot.ylabel     "compile time"
            plot.format     'y "%f s"'

            curves = [:overload, :noexcept, :linear_constexpr, :structs,
                      :specialization, :aliases, :short_circuit_structs]

            for curve in curves
                opts = opts_.clone
                opts[curve] = true
                points = generate_points(1..10) { |n|
                    opts[:bools] = (0..n).collect{'false_'} << 'true_'
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
