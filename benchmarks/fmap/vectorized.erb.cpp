<%= render('_base.erb') %>

template <template <typename ...> class f, typename xs>
struct map;

template <template <typename ...> class f, typename ...xs>
struct map<f, list<xs...>> {
    using type = list<typename f<xs>::type...>;
};

<%= render('_main.erb') %>