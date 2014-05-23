<% render('_main.erb') do %>
    template <template <typename ...> class f, typename xs,
              bool = is_empty<xs>::value>
    struct map
        : cons<
            typename f<typename head<xs>::type>::type,
            typename map<f, typename tail<xs>::type>::type
        >
    { };

    template <template <typename ...> class f, typename xs>
    struct map<f, xs, true> {
        using type = xs;
    };
<% end %>