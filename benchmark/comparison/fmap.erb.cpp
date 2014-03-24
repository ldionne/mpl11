int main() { }

<% n = env.input %>

<% if !env.rules %>
    #define BOOST_MPL11_NO_REWRITE_RULES
<% end %>

<% if env.config == :mpl11_list || env.fair %>
    #include <boost/mpl11/list.hpp>
<% end %>

<% if env.config == :mpl_vector || env.fair %>
    #include <boost/mpl/vector/vector<%= n.round_up(1) %>.hpp>
<% end %>

<% if env.config == :mpl_list || env.fair %>
    #include <boost/mpl/list/list<%= n.round_up(1) %>.hpp>
<% end %>


template <unsigned> struct x;

<%
    xs = (0...n).collect{ |i| "x<#{i}>" }.join(", ")
    case env.config
        when :mpl11_list
%>

    using dataset = boost::mpl11::list_<    <%= xs %>   >;

<% when :mpl_vector %>

    using dataset = boost::mpl:: <%= "vector#{n}<#{xs}>" %>;

<% when :mpl_list %>

    using dataset = boost::mpl:: <%= "list#{n}<#{xs}>" %>;

<% end %>

<% if env.operation == :fmap && (env.config =~ /^mpl_/ || env.fair) %>
    #include <boost/mpl/transform.hpp>
<% end %>



struct f {
    using type = f;
    template <typename ...>
    struct apply { struct type; };
};


<% case env.operation
    when :fmap %>

        <% if env.config =~ /^mpl_/ %>
            template <typename f, typename dataset>
            using fmap = boost::mpl::transform<dataset, f>;
        <% else %>
            using boost::mpl11::fmap;
        <% end %>

        using Go = fmap<f, dataset>::type;

<% end %>
