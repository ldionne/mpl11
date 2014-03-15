
<% if env[:flat] %>

    template <unsigned i>
    struct metafunction { struct type; };

    <% for i in 0..env[:input] %>
        template struct metafunction<   <%= i %>    >;
    <% end %>

<% elsif env[:recursive] %>

    template <unsigned i>
    struct metafunction
        : metafunction<i - 1>
    { };

    template <>
    struct metafunction<0> { struct type; };

    template struct metafunction<   <%= env[:input] %>    >;

<% end %>


int main() { }
