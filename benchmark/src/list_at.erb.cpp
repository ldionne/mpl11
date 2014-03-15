<%
    xs = (0..env[:input]).collect{ |i| "x<#{i}>" }.join(", ")
    vectorN = env[:input].round_up(1)
    last_index = env[:input] - 1
%>

<% if env[:mpl11] or env[:fair] %>
    #include <boost/mpl11/list.hpp>
<% end %>

<% if env[:mpl] or env[:fair] %>
    #include <boost/mpl/at.hpp>
    #include <boost/mpl/vector/vector<%= vectorN %>.hpp>
<% end %>


template <unsigned>
struct x { struct type; };

template <typename a, typename b>
struct is_same { static constexpr bool value = false; };

template <typename a>
struct is_same<a, a> { static constexpr bool value = true; };

<% if env[:mpl] %>

    using dataset = boost::mpl:: <%= "vector#{env[:input]}<#{xs}>" %>;
    static_assert(is_same<
        boost::mpl::at_c<dataset, <%= last_index %>     >::type,
        x<                        <%= last_index %>     >
    >::value, "");

<% elsif env[:mpl11] %>

    using dataset = boost::mpl11::list<     <%= xs %>   >;
    static_assert(is_same<
        boost::mpl11::at_c< <%= last_index %>, dataset>::type,
        x<                  <%= last_index %>         >::type
    >::value, "");

<% end %>

int main() { }
