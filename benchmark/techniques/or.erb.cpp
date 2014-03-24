#include <boost/mpl11/detail/std_conditional.hpp>


using boost::mpl11::detail::std_conditional;

template <bool B>
struct bool_ { static constexpr bool value = B; };

using true_ = bool_<true>;
using false_ = bool_<false>;


<% case env[:config]
    when :overload %>

    template <typename ...T>
    constexpr bool all_pointers(T*...) { return true; }

    template <typename ...T>
    constexpr bool all_pointers(T...) { return false; }

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !all_pointers(
            ((typename std_conditional<T::value, int, void*>::type)0)...
        );
    };

    template <>
    struct or_<> {
        static constexpr bool value = false;
    };

<% when :noexcept %>

    void allow_expansion(...) noexcept;

    struct non_throwing { non_throwing() noexcept { } };
    struct throwing { throwing() { throw; } };

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !noexcept(
            allow_expansion(
                typename std_conditional<
                    T::value, throwing, non_throwing
                >::type{}...
            )
        );
    };

<% when :recursive_constexpr %>

    template <typename Iter>
    constexpr bool or_impl(Iter first, Iter last) {
        return first == last ? false
                             : *first || or_impl(first+1, last);
    }

    template <typename ...T>
    struct or_ {
        static constexpr bool tmp[] = {T::value...};
        static constexpr bool value = or_impl(&tmp[0], &tmp[sizeof...(T)]);
    };

    template <>
    struct or_<> {
        static constexpr bool value = false;
    };

<% when :structs %>

    template <typename ...T>
    struct or_ {
        static constexpr bool value = false;
    };

    template <typename Head, typename ...Tail>
    struct or_<Head, Tail...> {
        static constexpr bool value = Head::value || or_<Tail...>::value;
    };

<% when :specialization %>

    template <typename ...T>
    struct or_ {
        static constexpr bool value = true;
    };

    template <template <bool> class ...Bool>
    struct or_<Bool<false>...> {
        static constexpr bool value = false;
    };

<% when :aliases %>

#if 0 // This does not work
    template <bool ValueOfLast, bool WeAreDone>
    struct or_impl;

    template <>
    struct or_impl<false, false> {
        template <typename F1, typename ...Fn>
        using apply = typename or_impl<
                        static_cast<bool>(F1::type::value),
                        sizeof...(Fn) == 0
                      >::template apply<Fn...>;
    };

    template <>
    struct or_impl<false, true> {
        template <typename ...Fn>
        using apply = false_;
    };

    template <bool WeAreDone>
    struct or_impl<true, WeAreDone> {
        template <typename ...>
        using apply = true_;
    };

    template <typename ...Fn>
    struct or_
        : or_impl<false, false>::template apply<Fn...>
    { };

    template <>
    struct or_<>
        : false_
    { };
#endif

<% when :short_circuit_structs %>

    template <bool b, typename ...c>
    struct or_impl : bool_<b> { };

    template <typename c, typename ...cs>
    struct or_impl<false, c, cs...> : or_impl<c::value, cs...> { };

    template <typename ...c>
    struct or_ : or_impl<false, c...> { };

<% end %>

static_assert(!or_<>::value, "");

static_assert( or_<true_>::value, "");
static_assert(!or_<false_>::value, "");

static_assert( or_<true_, true_>::value, "");
static_assert( or_<true_, false_>::value, "");
static_assert( or_<false_, true_>::value, "");
static_assert(!or_<false_, false_>::value, "");

<%
    bools = (0..env[:input]).collect{'false_'} << 'true_'
%>

static_assert(or_<    <%= bools.join(', ') %>  >::value, "");

int main() { }
