
#include <boost/mpl11/detail/std_index_sequence.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


using boost::mpl11::detail::make_std_index_sequence;
using boost::mpl11::detail::std_index_sequence;
using boost::mpl11::detail::std_is_same;
using boost::mpl11::detail::std_size_t;

<% case env[:config]
    when :overload %>

    template <typename T>
    struct no_decay;

    template <typename Head>
    struct at_impl;

    // ldionne:
    // I first encountered this technique at "github.com/dabrahams/mpl11".
    // Credit goes to Dave Abrahams.
    template <std_size_t ...Head>
    struct at_impl<std_index_sequence<Head...>> {
        template <typename Nth>
        static Nth apply(decltype((Head, (void*)0))..., no_decay<Nth>*, ...);
    };

    template <std_size_t N, typename ...Args>
    struct at {
        using type = decltype(
            at_impl<typename make_std_index_sequence<N>::type>::apply(
                (no_decay<Args>*)nullptr...
            )
        );
    };

<% when :multiple_inheritance %>

    template <typename T>
    struct no_decay {
        using type = T;
    };

    template <std_size_t Index, typename Value>
    struct holder { };

    template <typename Indices, typename ...T>
    struct vector;

    // This is equivalent to implementing at_key with multiple inheritance,
    // except that keys are indices here.
    template <std_size_t ...Indices, typename ...T>
    struct vector<std_index_sequence<Indices...>, T...>
        : holder<Indices, T>...
    {
        template <std_size_t Index, typename Value>
        static no_decay<Value> at_impl(holder<Index, Value>*);
    };

    template <std_size_t N, typename ...Args>
    struct at {
        using Vector = vector<
            typename make_std_index_sequence<sizeof...(Args)>::type, Args...
        >;
        using type = typename decltype(
            Vector::template at_impl<N>((Vector*)nullptr)
        )::type;
    };

<% end %>

template <unsigned>
struct t;

#define assert_same(...) \
    static_assert(std_is_same<__VA_ARGS__>::value, #__VA_ARGS__)

assert_same(at<0, t<0>>::type, t<0>);
assert_same(at<0, t<0>, t<1>>::type, t<0>);
assert_same(at<0, t<0>, t<1>, t<2>>::type, t<0>);

assert_same(at<1, t<0>, t<1>>::type, t<1>);
assert_same(at<1, t<0>, t<1>, t<2>>::type, t<1>);
assert_same(at<1, t<0>, t<1>, t<2>, t<3>>::type, t<1>);

assert_same(at<2, t<0>, t<1>, t<2>>::type, t<2>);
assert_same(at<2, t<0>, t<1>, t<2>, t<3>>::type, t<2>);
assert_same(at<2, t<0>, t<1>, t<2>, t<3>, t<4>>::type, t<2>);

<%
    n = env[:input]
    ts = (0..n).collect{ |i| "t<#{i}>" }.join ', '
    for i in 0...n
%>

    static_assert(std_is_same<
        at<     <%= i %>, <%= ts %>     >::type,
        t<      <%= i %>                >
    >::value, "");

<% end %>


int main() { }
