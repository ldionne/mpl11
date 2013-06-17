/*!
 * @file
 * This file defines `boost::mpl11::if_` and `boost::mpl11::if_c`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional/protect.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace if_detail {
template <bool Cond, typename Then>
struct branch {
    static constexpr bool condition = Cond;
    using then = Then;
};

template <bool Condition, typename Then, typename Else>
struct eval_conditional : eval<Then> { };

template <typename Then, typename Else>
struct eval_conditional<false, Then, Else> : eval<Else> { };


// We walk the branches until we encounter one whose condition is `true`,
// and pick its `then`. If there is no branch whose condition is `true`,
// we don't provide a nested `type`, which enables us to mimic the
// functionality provided by `enable_if`.
template <typename ...Branches>
struct evaluate_branches;

template <typename Branch, typename ...Rest>
struct evaluate_branches<Branch, Rest...>
    : eval_conditional<
        Branch::condition,
        identity<typename Branch::then>,
        evaluate_branches<Rest...>
    >
{ };

template <> struct evaluate_branches<> { };


template <typename ...Branches>
struct jump_table {
    template <bool Cond, typename Then>
    using append = jump_table<Branches..., branch<Cond, Then>>;

    struct evaluate : evaluate_branches<Branches...> { };
};

template <typename JumpTable> struct else_if_interface;
template <typename JumpTable> struct else_interface;
template <typename JumpTable> struct eval_interface;

struct if_interface {
    using JumpTable = jump_table<>;

    template <bool Cond, typename ...>
    struct if_c;

    template <typename Cond, typename ...Args>
    using if_ = if_c<Cond::type::value, Args...>;

    template <bool Cond>
    struct if_c<Cond>
        : eval_interface<
            // emulate enable_if
            typename JumpTable::template append<Cond, void>
        >
    {
        template <typename Then>
        using then = if_c<Cond, Then>;
    };

    template <bool Cond, typename Then>
    struct if_c<Cond, Then>
        : else_if_interface<
            typename JumpTable::template append<Cond, Then>
        >,
        else_interface<
            typename JumpTable::template append<Cond, Then>
        >,
        eval_interface<
            typename JumpTable::template append<Cond, Then>
        >
    { };

    template <bool Cond, typename Then, typename Else>
    struct if_c<Cond, Then, Else>
        : else_interface<
            typename JumpTable::template append<Cond, Then>
        >::template else_<Else>
    { };
};

template <typename JumpTable>
struct else_if_interface {
    template <bool Cond, typename ...>
    struct else_if_c;

    template <typename Cond, typename ...Args>
    using else_if = else_if_c<Cond::type::value, Args...>;

    template <bool Cond>
    struct else_if_c<Cond>
        : eval_interface<
            // emulate enable_if
            typename JumpTable::template append<Cond, void>
        >
    {
        template <typename Then>
        using then = else_if_c<Cond, Then>;
    };

    template <bool Cond, typename Then>
    struct else_if_c<Cond, Then>
        : else_if_interface<
            typename JumpTable::template append<Cond, Then>
        >,
        else_interface<
            typename JumpTable::template append<Cond, Then>
        >,
        eval_interface<
            typename JumpTable::template append<Cond, Then>
        >
    { };

    template <bool Cond, typename Then, typename Else>
    struct else_if_c<Cond, Then, Else>
        : else_interface<
            typename JumpTable::template append<Cond, Then>
        >::template else_<Else>
    { };
};

template <typename JumpTable>
struct else_interface {
    template <typename Else>
    struct else_
        : eval_interface<
            typename JumpTable::template append<true, Else>
        >
    { };
};

template <typename JumpTable>
struct eval_interface
    : JumpTable::evaluate
{ };
} // end namespace if_detail

template <bool Cond, typename ...Args>
struct if_c
    : if_detail::if_interface::template if_c<Cond, Args...>
{ };

template <typename Cond, typename ...Args>
using if_ = if_c<Cond::type::value, Args...>;
}}}

#endif // !BOOST_MPL11_IF_HPP
