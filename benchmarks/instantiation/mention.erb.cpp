template <unsigned i>
struct metafunction { };

<% (0...n).each do |i| %>
    using go<%= i %> = metafunction<<%= i %>>;
<% end %>