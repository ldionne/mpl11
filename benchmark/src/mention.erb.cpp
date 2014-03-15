
template <int>
struct x { };

<% if env[:instantiate] %>

    <% for i in 0..env[:input] %>
        template struct x<  <%= i %>    >;
    <% end %>

<% elsif env[:mention] %>

    <% for i in 0..env[:input] %>
        using <%= "x#{i}" %> = x<   <%= i %>    >;
    <% end %>

<% end %>

int main() { }
