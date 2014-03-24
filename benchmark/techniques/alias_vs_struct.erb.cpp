int main() { }

<% case env.config
    when :alias %>

    template <int>
    using x = int;

<% when :struct %>

    template <int>
    struct x { };

<% end %>

<%=
    (0..env.input).map { |n|
        "using x#{n} = x<#{n}>;"
    }.join("\n")
%>
