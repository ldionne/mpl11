<%
    n = env[:input]

    case env[:config]
        when :flat_nested_type
%>

    template <unsigned i>
    struct metafunction { using type = metafunction; };

    <% for i in 0..n %>
        using Go<%= i %> = metafunction<     <%= i %>   >::type;
    <% end %>

<% when :recursive_forwarding %>

    template <unsigned i>
    struct metafunction
        : metafunction<i - 1>
    { };

    template <>
    struct metafunction<0> { using type = metafunction; };

    using Go = metafunction<    <%= n %>    >::type;

<% when :recursive_nested_type %>

    template <unsigned i>
    struct metafunction {
        using type = typename metafunction<i - 1>::type;
    };

    template <>
    struct metafunction<0> { using type = metafunction; };

    using Go = metafunction<    <%= n %>      >::type;

<% end %>


int main() { }
