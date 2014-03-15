
template <bool Condition, typename Then, typename Else>
struct conditional { using type = Then; };

template <typename Then, typename Else>
struct conditional<false, Then, Else> { using type = Else; };

<% if env[:overload] %>

    template <typename ...T>
    constexpr bool all_pointers(T*...) { return true; }

    template <typename ...T>
    constexpr bool all_pointers(T...) { return false; }

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !all_pointers(
            ((typename conditional<T::value, int, void*>::type)0)...
        );
    };

    template <>
    struct or_<> {
        static constexpr bool value = false;
    };

<% elsif env[:noexcept] %>

    void allow_expansion(...) noexcept;

    struct non_throwing { non_throwing() noexcept { } };
    struct throwing { throwing() { throw; } };

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !noexcept(
            allow_expansion(
                typename conditional<
                    T::value, throwing, non_throwing
                >::type{}...
            )
        );
    };

<% elsif env[:linear_constexpr] %>

    // This has horrible performance and we sometimes hit the recursion
    // limit on Clang.
    constexpr bool or_impl() { return false; }

    template <typename ...Tail>
    constexpr bool or_impl(bool head, Tail... tail) {
        return head || or_impl(tail...);
    }

    template <typename ...T>
    struct or_ {
        static constexpr bool value = or_impl(T::value...);
    };

<% elsif env[:structs] %>

    // Surprisingly (for me), this is better than the above solution using
    // constexpr functions, but it still sucks and we hit the recursion limit
    // on Clang quite easily.
    template <typename ...T>
    struct or_ {
        static constexpr bool value = false;
    };

    template <typename Head, typename ...Tail>
    struct or_<Head, Tail...> {
        static constexpr bool value = Head::value || or_<Tail...>::value;
    };

<% elsif env[:specialization] %>

    // I don't know why I did not think of this earlier. This is clearly
    // the simplest method and it's also the fastest. lol
    template <typename ...T>
    struct or_ {
        static constexpr bool value = true;
    };

    template <template <bool> class ...Bool>
    struct or_<Bool<false>...> {
        static constexpr bool value = false;
    };

<% elsif env[:aliases] %>

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

<% elsif env[:short_circuit_structs] %>

    template <bool b, typename ...c>
    struct or_impl : bool_<b> { };

    template <typename c, typename ...cs>
    struct or_impl<false, c, cs...> : or_impl<c::type::value, cs...> { };

    template <typename ...c>
    struct or_ : or_impl<false, c...> { };

<% end %>

template <bool B>
struct bool_ { static constexpr bool value = B; };

using true_ = bool_<true>;
using false_ = bool_<false>;

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
