<% if env[:config] == :mpl %>
    #include <boost/mpl/long.hpp>
    #include <boost/mpl/plus.hpp>
<% end %>

<% if env[:config] == :mpl11 %>
    #include <boost/mpl11/integer.hpp>
<% end %>


<% case env[:config]
    when :mpl %>

    template <long ...n>
    using plus = boost::mpl::plus<boost::mpl::long_<n>...>;

<% when :mpl11 %>

    template <long ...n>
    using plus = boost::mpl11::plus<boost::mpl11::long_<n>...>;

<% end %>

<%
    ints = (0...env[:input]).to_a
%>

static_assert(
    plus<   <%= ints.join(", ") %>   >::value
                        ==
            <%= ints.reduce :+ %>
, "");


int main() { }
