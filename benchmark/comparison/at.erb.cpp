
#include <boost/mpl11/detail/std_is_same.hpp>


<%
    n = env[:input]
    xs = (0...n).collect{ |i| "x<#{i}>" }.join(", ")
%>

<% if env[:config] == :mpl11_list || env[:fair]  %>
    #include <boost/mpl11/list.hpp>
<% end %>

<% if env[:config] == :mpl_vector || env[:fair] %>
    #include <boost/mpl/at.hpp>
    #include <boost/mpl/vector/vector<%= n.round_up(1) %>.hpp>
<% end %>

<% if env[:config] == :mpl_list || env[:fair] %>
    #include <boost/mpl/at.hpp>
    #include <boost/mpl/list/list<%= n.round_up(1) %>.hpp>
<% end %>


template <unsigned> struct x;

<% case env[:config]
    when :mpl_vector %>

    using dataset = boost::mpl:: <%= "vector#{n}<#{xs}>" %>;
    using boost::mpl::at_c;

<% when :mpl_list %>

    using dataset = boost::mpl:: <%= "list#{n}<#{xs}>" %>;
    using boost::mpl::at_c;

<% when :mpl11_list %>

    template <typename xs, unsigned long n>
    using at_c = boost::mpl11::at_c<n, xs>;

    using dataset = boost::mpl11::list_<     <%= xs %>   >;

<% end %>

static_assert(boost::mpl11::detail::std_is_same<
    at_c<dataset,   <%= n-1 %>      >::type,
    x<              <%= n-1 %>      >
>::value, "");

int main() { }
