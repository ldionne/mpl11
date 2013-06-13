/*!
 * @file
 * This file defines `boost::mpl11::if_` and `boost::mpl11::if_c`.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/empty_base.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace if_detail {
    struct no_then;
    struct no_else;
}

template <typename M>
struct eval;

template <bool Cond,
          typename Then = if_detail::no_then,
          typename Else = if_detail::no_else>
struct if_c;

template <typename Cond,
          typename Then = if_detail::no_then,
          typename Else = if_detail::no_else>
struct if_
    : if_c<Cond::type::value, Then, Else>
{ };

namespace if_detail {
//////////////////////////////////////////////////////////////////////////////
namespace foo {
template <typename ...Branches>
class jump_table {
    template <bool Cond, typename Then>
    struct branch {
        static constexpr bool condition = Cond;
        using action = Then;
    };

public:
    template <bool Cond, typename Action>
    using append = jump_table<Branches..., branch<Cond, Action>>;
    using result = ; // fold branches and pick the first true one.
                     // in the end, if no branches are true, we must
                     // not have a nested type in order to mimic enable_if
};

template <typename JumpTable>
struct else_if_interface {
    template <bool Cond, typename Then>
    struct else_if_c
        : else_if_interface<
            typename JumpTable::template append<Cond, Then>
        >
    { };

    template <typename Else>
    struct else_
        : else_interface<
            typename JumpTable::template append<true, Else>
        >
    { };
};

template <typename JumpTable>
struct else_interface {
    using type = typename JumpTable::result;
};



template <bool Cond, typename Then = no_then>
struct if_c
    : else_if_interface<
        typename jump_table<>::template append<Cond, Then>
    >
{ };

template <bool Cond>
struct if_c<Cond, no_then> {
    template <typename Then>
    using then = if_c<Cond, Then>;
};
}
//////////////////////////////////////////////////////////////////////////////

template <typename T>
struct unwrap_eval { using type = T; };

template <typename T>
struct unwrap_eval<eval<T>> : T { };

template <bool Cond, typename Then, typename Else>
struct conditional : unwrap_eval<Then> { };

template <typename Then, typename Else>
struct conditional<false, Then, Else> : unwrap_eval<Else> { };

template <bool Cond, typename Then>
struct else_if_and_else {
    template <bool Cond2, typename Then2 = no_then, typename Else = no_else>
    struct else_if_c
        : if_c<Cond || Cond2,
            typename if_c<Cond, Then, Then2>::type,
            Else
        >
    { };

    template <typename Cond2, typename Then2 = no_then, typename Else=no_else>
    struct else_if
        : else_if_c<Cond2::type::value, Then2, Else>
    { };

    template <typename Else>
    struct else_
        : if_c<Cond, Then, Else>
    { };
};
} // end namespace if_detail

template <bool Cond, typename Then, typename Else>
struct if_c
    : if_detail::conditional<Cond, Then, Else>
{ };

template <bool Cond, typename Then>
struct if_c<Cond, Then, if_detail::no_else>
    : if_c<Cond, Then, eval<empty_base>>,
      if_detail::else_if_and_else<Cond, Then>
{ };

template <bool Cond>
struct if_c<Cond, if_detail::no_then, if_detail::no_else>
    : if_c<Cond, void, if_detail::no_else>
{
    template <typename Then>
    struct then
        : if_c<Cond, Then, if_detail::no_else>
    { };
};
}}}

#endif // !BOOST_MPL11_IF_HPP
