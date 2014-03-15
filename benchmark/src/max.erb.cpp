
<% if env[:standard_recursion] %>

    template <long a0, long a1, long ...aN>
    struct max
        : max<a0, max<a1, aN...>::value>
    { };

    template <long a0, long a1>
    struct max<a0, a1> {
        static constexpr long value = a0 < a1 ? a1 : a0;
    };

<% elsif env[:union] %>

    template <long a0, long a1, long ...aN>
    struct max
        : max<a0, max<a1, aN...>::value>
    { };

    template <long a0, long a1>
    struct max<a0, a1> {
        static constexpr long value = a0 < a1 ? a1 : a0;
    };

    template <long a0, long a1, long a2, long a3, long a4, long a5, long a6>
    union alignas(char) batch_max_impl {
        char _a0[a0+1];
        char _a1[a1+1];
        char _a2[a2+1];
        char _a3[a3+1];
        char _a4[a4+1];
        char _a5[a5+1];
        char _a6[a6+1];
    };

    template <long ...ai>
    using batch_max = max<
        // The maximum of all the positive integers.
        sizeof(batch_max_impl<(ai < 0 ? 0 : ai)...>) - 1,

        // The minimum of all the negative integers.
        -(sizeof(batch_max_impl<(ai < 0 ? -ai : 0)...>) - 1)
    >;

    template <long a0, long a1, long a2, long a3, long a4, long a5, long a6>
    struct max<a0, a1, a2, a3, a4, a5, a6>
        : batch_max<a0, a1, a2, a3, a4, a5, a6>
    { };

    template <
        long a0, long a1, long a2, long a3, long a4, long a5, long a6,
        long a7, long ...aN
    >
    struct max<a0, a1, a2, a3, a4, a5, a6, a7, aN...>
        : max<max<a0, a1, a2, a3, a4, a5, a6>::value, a7, aN...>
    { };

<% elsif env[:argwise] %>

    template <long v>
    struct integer_c;

    template <typename a0, typename a1, typename ...aN>
    struct max_impl;

    template <template <long> class ...Ints, long v>
    struct max_impl<Ints<v>...> {
        static constexpr auto value = v;
    };

    template <long v, long ...vs>
    struct max_impl<integer_c<v>, integer_c<vs>...>
        : max_impl<integer_c<v>, integer_c<(v < vs ? vs : v)>...>
    { };

    template <long a0, long a1, long ...aN>
    struct max
        : max_impl<integer_c<a0>, integer_c<a1>, integer_c<aN>...>
    { };

<% end %>

static_assert(max<-1, 0>::value == 0, "");
static_assert(max<-1, 1>::value == 1, "");
static_assert(max<-1, -4>::value == -1, "");

static_assert(max<0, 0>::value == 0, "");
static_assert(max<0, 1>::value == 1, "");
static_assert(max<1, 0>::value == 1, "");
static_assert(max<1, 1>::value == 1, "");

static_assert(max<0, 1, 2>::value == 2, "");
static_assert(max<0, 1, 2, 3>::value == 3, "");
static_assert(max<0, 4, 2, 3>::value == 4, "");
static_assert(max<0, 1, 2, 3, 2, 3>::value == 3, "");

<%
    n = env[:input]
    ints = (0..n).to_a.shuffle
    # ints = ((0..n/2).to_a + (0..n-n/2).to_a).shuffle
%>

static_assert(
    max<    <%= ints.join(',') %>    >::value
                    ==
            <%= ints.max %>
, "");


int main() { }
