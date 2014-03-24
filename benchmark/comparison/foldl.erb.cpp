<%
    n = env[:input]
    xs = (1..n).collect{ |i| "x<#{i}>" }.join(", ")
%>

<% if env[:config] == :mpl11_list || env[:fair] %>
    #include <boost/mpl11/list.hpp>
<% end %>

<% if env[:config] == :mpl_vector || env[:fair] %>
    #include <boost/mpl/fold.hpp>
    #include <boost/mpl/vector/vector<%= n.round_up(1) %>.hpp>
<% end %>

<% if env[:config] == :mpl_list || env[:fair] %>
    #include <boost/mpl/fold.hpp>
    #include <boost/mpl/list/list<%= n.round_up(1) %>.hpp>
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


<% case env[:config]
    when :mpl_vector %>

    using dataset = <%= "boost::mpl::vector#{n}<#{xs}>" %>;
    using Go = boost::mpl::fold<dataset, state, f>::type;

<% when :mpl_list %>

    using dataset = <%= "boost::mpl::list#{n}<#{xs}>" %>;
    using Go = boost::mpl::fold<dataset, state, f>::type;

<% when :mpl11_list %>

    using dataset = boost::mpl11::list<     <%= xs %>   >;
    using Go = boost::mpl11::foldl<f, state, dataset>::type;

<% end %>

int main() { }
