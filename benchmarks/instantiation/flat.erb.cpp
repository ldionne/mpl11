template <unsigned i>
struct metafunction { using type = metafunction; };

<% (0...n).each do |i| %>
    using go<%= i %> = metafunction<<%= i %>>::type;
<% end %>