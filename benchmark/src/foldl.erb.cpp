<%
    xs = (1..env[:input]).collect{ |i| "x<#{i}>" }.join ', '
%>

<% if env[:mpl11] or env[:fair] %>
    #include <boost/mpl11/list.hpp>
<% end %>

<% if env[:mpl] or (env[:input] <= 50 and env[:fair]) %>
    #include <boost/mpl/fold.hpp>
    #include <boost/mpl/vector/vector<%= env[:input].round_up(1) %>.hpp>
<% end %>


template <unsigned>
struct x;

struct state { struct type; };

struct f {
    using type = f;

    template <typename, typename>
    struct apply {
        struct type;
    };
};


<% if env[:mpl] %>

    using dataset = <%= "boost::mpl::vector#{env[:input]}<#{xs}>" %>;
    using Go = boost::mpl::fold<dataset, state, f>::type;

<% elsif env[:mpl11] %>

    using dataset = boost::mpl11::list<     <%= xs %>   >;
    using Go = boost::mpl11::foldl<f, state, dataset>::type;

<% elsif env[:aliases] %>

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

    using Go = foldl<f, state,  <%= xs %>     >::type;

<% elsif env[:standard_recursion] %>

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

    using Go = foldl<f, state,  <%= xs %>     >::type;

<% end %>

int main() { }
