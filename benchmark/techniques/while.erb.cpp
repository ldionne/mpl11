#include <boost/mpl11/detail/std_is_same.hpp>

<% case env[:config]
    when :aliases %>

    template <bool Continue>
    struct while_impl {
        template <typename Pred, typename F, typename PrevState,
                  typename State = typename F::template apply<PrevState>::type>
        using apply = typename while_impl<Pred::template apply<State>::value>::
                      template apply<Pred, F, State>;
    };

    template <>
    struct while_impl<false> {
        template <typename Pred, typename F, typename State>
        struct apply {
            using type = State;
        };
    };

    template <typename Pred, typename F, typename State>
    using while_ = typename while_impl<Pred::template apply<State>::value>::
                   template apply<Pred, F, State>;

<% when :standard_recursion %>

    template <typename Pred, typename F, typename State,
              bool = Pred::template apply<State>::value>
    struct while_;

    template <typename Pred, typename F, typename State>
    struct while_<Pred, F, State, true>
        : while_<Pred, F, typename F::template apply<State>::type>
    { };

    template <typename Pred, typename F, typename State>
    struct while_<Pred, F, State, false> {
        using type = State;
    };

<% end %>

template <int> struct x;

struct increment {
    template <typename X>
    struct apply;

    template <int i>
    struct apply<x<i>> {
        using type = x<i+1>;
    };
};

template <typename X>
struct different_from {
    template <typename, typename = void>
    struct apply { static constexpr bool value = true; };

    template <typename Dummy>
    struct apply<X, Dummy> { static constexpr bool value = false; };
};

template <typename X>
struct test_until {
    static_assert(boost::mpl11::detail::std_is_same<
        typename while_<different_from<X>, increment, x<0>>::type,
        X
    >::value, "");
};

struct tests :
    test_until<x<0>>,
    test_until<x<1>>,
    test_until<x<2>>,
    test_until<x<3>>,
    test_until<x<4>>
{ };

using Go = while_<different_from<x<     <%= env[:input] %>     >>, increment, x<0>>::type;


int main() { }
