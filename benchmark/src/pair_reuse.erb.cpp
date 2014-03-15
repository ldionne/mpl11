template <int> struct x;

<% if env[:reuse] %>

    template <int>
    struct int_;

    template <typename, typename>
    struct pair { };

    <% for i in 0..env[:input] %>
        template struct pair<
            int_<   <%= i %>    >,
            x<      <%= i %>    >
        >;
    <% end %>

<% elsif env[:specialized] %>

    template <int, typename>
    struct pair { };

    <% for i in 0..env[:input] %>
        template struct pair<
                    <%= i %>     ,
            x<      <%= i %>    >
        >;
    <% end %>

<% end %>

int main() { }
