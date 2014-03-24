#include <boost/mpl11/detail/std_is_same.hpp>

template <typename T>
struct no_decay {
    using type = T;
};

template <typename First, typename Second>
struct pair { };

<% case env[:config]
    when :multiple_inheritance %>

    // ldionne:
    // I first encountered this technique in a post by Augustin Bergé on
    // the Boost mailing list. Thanks!
    template <typename ...Pairs>
    struct map : Pairs... {
        template <typename Key, typename Value>
        static no_decay<Value> at_key_impl(pair<Key, Value>*);
    };

    template <typename Map, typename Key>
    using at_key = decltype(Map::template at_key_impl<Key>((Map*)nullptr));

<% when :single_inheritance %>

    template <typename ...Pairs>
    struct map {
        template <typename Key>
        static typename Key::error_not_found at_key_impl(no_decay<Key>*);
    };

    template <typename Key, typename Value, typename ...Rest>
    struct map<pair<Key, Value>, Rest...> : map<Rest...> {
        using map<Rest...>::at_key_impl;
        static no_decay<Value> at_key_impl(no_decay<Key>*);
    };

    template <typename Map, typename Key>
    using at_key = decltype(Map::at_key_impl((no_decay<Key>*)nullptr));

<% end %>

<%
    n = env[:input]
    kvs = (0..n).collect { |i| "pair<k<#{i}>, v<#{i}>>" }.join(", ")
%>

template <int> struct k;
template <int> struct v;

using Go = at_key<
    map<    <%= kvs %>          >,
            <%= "k<#{n}>" %>
>::type;

static_assert(boost::mpl11::detail::std_is_same<
    Go, <%= "v<#{n}>" %>
>::value, "");


int main() { }
