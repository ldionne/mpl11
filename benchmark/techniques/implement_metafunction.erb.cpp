template <int>
struct x { using type = x; };

<% case env[:config]
    when :specialize %>

    template <typename x>
    struct metafunction;

    template <int>
    struct x;

    template <int i>
    struct metafunction<x<i>> {
        using type = x<i>;
    };

<% when :delegate %>

    template <typename x>
    struct metafunction {
        using type = typename x::type;
    };

<% end %>

<% 0.upto(env[:input]) do |i| %>
    template struct metafunction<x<     <%= i %>    >>;
<% end %>


int main() { }
