using size_t = decltype(sizeof(int));

template <size_t index, typename x, typename ...xs>
struct at_index {
    using type = typename at_index<index - 1, xs...>::type;
};

template <typename x, typename ...xs>
struct at_index<0, x, xs...>
    : x
{ };

<%= render('_main.erb') %>