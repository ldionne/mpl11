<% if env[:config] == :sizeof_trick || env[:fair] %>
    #include <boost/mpl11/detail/std_index_sequence.hpp>
    #include <boost/mpl11/detail/std_size_t.hpp>

    using boost::mpl11::detail::make_std_index_sequence;
    using boost::mpl11::detail::std_index_sequence;
    using boost::mpl11::detail::std_size_t;
<% end %>


<% case env[:config]
    when :accumulating_constexpr %>

    constexpr long sum_helper(long acc, long n)
    { return acc + n; }

    template <typename ...T>
    constexpr long sum_helper(long acc, long a, T... n)
    { return sum_helper(acc + a, n...); }

    template <long a, long b, long ...n>
    struct plus {
        static constexpr long value = sum_helper(a, b, n...);
    };

<% when :recursive_constexpr %>

    constexpr long sum_helper(long a, long b)
    { return a + b; }

    template <typename ...T>
    constexpr long sum_helper(long a, long b, T... n)
    { return a + sum_helper(b, n...); }

    template <long a, long b, long ...n>
    struct plus {
        static constexpr long value = sum_helper(a, b, n...);
    };

<% when :recursive_struct %>

    template <long a, long b, long ...n>
    struct plus {
        static constexpr long value = plus<a + b, n...>::value;
    };

    template <long a, long b>
    struct plus<a, b> {
        static constexpr long value = a + b;
    };

<% when :sizeof_trick %>

    template <unsigned long long size, unsigned make_unique = 0>
    class alignas(char) padding { char x[size]; };

    template <typename ...xs>
    struct inherit : xs... { };

    // Computes the sum of unsigned integers n. Note that compilation will
    // fail if any of the n's is < 0. However, we still use long because
    // that's the type used by `sum`.
    template <typename indices, long ...n>
    struct sum_helper;

    template <std_size_t ...i>
    struct sum_helper<std_index_sequence<i...>> {
        static constexpr long value = 0;
    };

    // NOTE:
    // I'm not sure this will always work. I'm unfamiliar with the details
    // of structure alignment. If padding was to be added between the
    // `padding`s in `inherit` below, this could screw up the whole thing.
    template <std_size_t ...i, long ...n>
    struct sum_helper<std_index_sequence<i...>, n...> {
        static constexpr long value =
            // We use n+1 to avoid 0-sized arrays, and we pass the index to
            // padding<> to avoid deriving several times from the same base
            // class.
            sizeof(inherit<padding<n+1, i>...>)
            // We remove the exceeding size that we added just above.
            - sizeof...(n);
    };

    template <long a, long b, long ...n>
    struct plus {
        using Indices = typename make_std_index_sequence<sizeof...(n)>::type;

        static constexpr long value =
            a + b +
            sum_helper<Indices, (n > 0 ? n : 0)...>::value -
            sum_helper<Indices, (n < 0 ? -n : 0)...>::value;
    };

<% end %>


static_assert(plus<0, -2>::value == 0 - 2, "");
static_assert(plus<0, -1>::value == 0 - 1, "");
static_assert(plus<0,  0>::value == 0 + 0, "");
static_assert(plus<0,  1>::value == 0 + 1, "");
static_assert(plus<0,  2>::value == 0 + 2, "");

static_assert(plus<1, 2>::value == 1 + 2, "");
static_assert(plus<1, 2, 3>::value == 1 + 2 + 3, "");
static_assert(plus<1, 2, 3, 4>::value == 1 + 2 + 3 + 4, "");

static_assert(plus<1, 1>::value == 1 + 1, "");
static_assert(plus<1, 1, 1, 1>::value == 1 + 1 + 1 + 1, "");


<%
    ints = (0..env[:input]).collect{ |i| (-1)**i * i }
%>

static_assert(
    plus<   <%= ints.join(", ") %>   >::value
                        ==
            <%= ints.reduce :+ %>
, "");


int main() { }
