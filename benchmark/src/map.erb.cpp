<%
    kvs = (0..env[:input]).collect { |i| "kv<#{i}, #{i}>" }.join(", ")
%>

template <typename T, typename U>
struct is_same { static constexpr bool value = false; };

template <typename T>
struct is_same<T, T> { static constexpr bool value = true; };

template <typename T>
struct no_decay {
    using type = T;
};

template <typename First, typename Second>
struct pair;


<% if env[:multiple_inheritance] %>

    template <typename Pair>
    struct holder { };

    // ldionne:
    // I first encountered this technique in a post by Augustin Bergé on
    // the Boost mailing list. Thanks!
    template <typename ...Pairs>
    struct map : holder<Pairs>... {
    private:
        template <typename Key, typename Value>
        static no_decay<Value> at_key_impl(holder<pair<Key, Value>>*);

    public:
        template <typename Key>
        struct at_key
            : decltype(map::at_key_impl<Key>((map*)nullptr))
        { };
    };

<% elsif env[:single_inheritance] %>

    template <typename ...Pairs>
    struct map {
        template <typename Key>
        static typename Key::error_not_found at_key_impl(no_decay<Key>*);
    };

    template <typename Key, typename Value, typename ...Rest>
    struct map<pair<Key, Value>, Rest...> : map<Rest...> {
        using map<Rest...>::at_key_impl;
        static no_decay<Value> at_key_impl(no_decay<Key>*);

        template <typename K>
        struct at_key
            : decltype(map::at_key_impl((no_decay<K>*)nullptr))
        { };
    };

<% end %>

template <int> struct k;
template <int> struct v;
template <int Key, int Value> using kv = pair<k<Key>, v<Value>>;

static_assert(is_same<
    map<kv<0, 0>, kv<1, 1>, kv<2, 2>>::at_key<k<0>>::type,
    v<0>
>::value, "");

static_assert(is_same<
    map<kv<0, 0>, kv<1, 1>, kv<2, 2>>::at_key<k<1>>::type,
    v<1>
>::value, "");

static_assert(is_same<
    map<<%= kvs %>>::at_key<k<<%= env[:input] %>>>::type,
    v<<%= env[:input] %>>
>::value, "");


int main() { }
