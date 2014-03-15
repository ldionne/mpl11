<% if env[:full_specialization] %>

    template <typename x>
    struct metafunction;

    <% for i in 0..env[:input] %>
        struct <%= "x#{i}" %>;

        template <>
        struct metafunction<    <%= "x#{i}" %>    > { struct type; };
    <% end %>

<% elsif env[:nested_type] %>

    template <typename x>
    struct metafunction {
        using type = typename x::type;
    };

    <% for i in 0..env[:input] %>
        struct <%= "x#{i}" %> { struct type; };
    <% end %>

<% end %>

<% for i in 0..env[:input] %>
    template struct metafunction<   <%= "x#{i}" %>     >;
<% end %>

int main() { }
