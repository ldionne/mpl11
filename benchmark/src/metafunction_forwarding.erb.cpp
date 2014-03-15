<% if env[:forwarding] %>

    template <unsigned i>
    struct metafunction
        : metafunction<i - 1>
    { };

    template <>
    struct metafunction<0> { struct type; };

<% elsif env[:nested_type] %>

    template <unsigned i>
    struct metafunction {
        using type = typename metafunction<i - 1>::type;
    };

    template <>
    struct metafunction<0> { struct type; };

<% end %>

template struct metafunction<   <%= env[:input] %>      >;


int main() { }
