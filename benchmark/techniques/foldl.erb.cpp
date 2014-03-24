<% case env[:config]
    when :aliases %>

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

<% when :standard_recursion %>

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

<% end %>

template <unsigned>
struct x;

struct state;

struct f {
    template <typename, typename>
    struct apply {
        struct type;
    };
};

<%
    n = env[:input]
    xs = (0...n).collect{ |i| "x<#{i}>" }.join(", ")
%>

using Go = foldl<f, state  <%= ", #{xs}" if n != 0 %>     >::type;

int main() { }
