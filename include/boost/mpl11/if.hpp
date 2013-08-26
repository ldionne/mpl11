/*!
 * @file
 * Defines `boost::mpl11::if_` and `boost::mpl11::if_c`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
namespace if_detail {
    template <typename Cond, typename Then>
    struct branch {
        using condition = Cond;
        using then = Then;
    };

    template <bool Condition, typename Then, typename Else>
    struct conditional
        : identity<Then>
    { };

    template <typename Then, typename Else>
    struct conditional<false, Then, Else>
        : identity<Else>
    { };

    // We walk the branches until we encounter one whose condition is `true`,
    // and pick its `then`. If there is no branch whose condition is `true`,
    // we don't provide a nested `type`, which enables us to mimic the
    // functionality provided by `enable_if`.
    template <typename ...Branches>
    struct evaluate_base { };

    template <typename Branch, typename ...Rest>
    struct evaluate_base<Branch, Rest...>
        : conditional<Branch::condition::type::value,
            identity<typename Branch::then>,
            evaluate_base<Rest...>
        >::type
    { };

    template <typename ...Branches>
    struct evaluate_complete;

    // Emulate enable_if.
    template <typename Cond, typename ...Branches>
    struct evaluate_then : evaluate_base<Branches..., branch<Cond, void>> {
        template <typename Then>
        using then = evaluate_complete<Branches..., branch<Cond, Then>>;
    };

    template <typename ...Branches>
    struct evaluate_complete : evaluate_base<Branches...> {
    private:
        template <typename Cond, typename ...OptionalThenElse>
        struct make_else_if;

    public:
        template <typename Cond, typename ...OptionalThenElse>
        using else_if = typename make_else_if<Cond, OptionalThenElse...>::type;

        template <bool Cond, typename ...Args>
        using else_if_c = else_if<bool_<Cond>, Args...>;

        template <typename Else>
        using else_ = evaluate_base<Branches..., branch<true_, Else>>;

    private:
        template <typename Cond>
        struct make_else_if<Cond>
            : identity<
                evaluate_then<Cond, Branches...>
            >
        { };

        template <typename Cond, typename Then>
        struct make_else_if<Cond, Then>
            : identity<
                typename else_if<Cond>::template then<Then>
            >
        { };

        template <typename Cond, typename Then, typename Else>
        struct make_else_if<Cond, Then, Else>
            : identity<
                typename else_if<Cond>::template then<Then>::
                template else_<Else>
            >
        { };
    };
} // end namespace if_detail

template <typename Cond, typename ...Args>
using if_ = typename if_detail::evaluate_complete<>::
            template else_if<Cond, Args...>;

template <bool Cond, typename ...Args>
using if_c = if_<bool_<Cond>, Args...>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IF_HPP
