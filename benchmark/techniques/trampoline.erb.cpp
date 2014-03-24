
int main() { }

using size_t = decltype(sizeof(int));

<% case env.config
    when :standard_recursion %>

    template <typename x, size_t n>
    struct unbox
        : unbox<typename unbox<x, n/2>::type, n - n/2>
    { };

    template <typename x>
    struct unbox<x, 0> { using type = x; };

    template <typename x>
    struct unbox<x, 1> : x { };

<% when /quantifier/ %>

    enum class Quantifier {
          zero
        , one
        , more
    };

    <% if /macro/ =~ env.config %>

        #define quantify(n)                                                 \
            (                                                               \
              (n) == 0 ? Quantifier::zero                                   \
            : (n) == 1 ? Quantifier::one                                    \
            :            Quantifier::more                                   \
            )                                                               \
        /**/

    <% elsif /constexpr/ =~ env.config %>

        constexpr Quantifier quantify(size_t n) {
            return n == 0 ? Quantifier::zero
                 : n == 1 ? Quantifier::one
                 :          Quantifier::more;
        }

    <% end %>

    template <Quantifier how_many_left>
    struct unbox_impl;

    template <>
    struct unbox_impl<Quantifier::more> {
        template <size_t n, typename x, size_t lft = n - n/2, size_t rgt = n/2>
        using apply = typename unbox_impl<quantify(lft)>::template apply<lft,
            typename unbox_impl<quantify(rgt)>::template apply<rgt, x>::type
        >;
    };

    template <>
    struct unbox_impl<Quantifier::zero> {
        template <size_t n, typename x>
        struct apply {
            using type = x;
        };
    };

    template <>
    struct unbox_impl<Quantifier::one> {
        template <size_t n, typename x>
        using apply = x;
    };

    template <typename x, size_t n>
    struct unbox
        : unbox_impl<quantify(n)>::template apply<n, x>
    { };

<% when :aliases %>

    template <bool one_or_zero_left>
    struct unbox_impl;

    template <>
    struct unbox_impl<false> {
        template <size_t n, typename x, size_t lft = n - n/2, size_t rgt = n/2>
        using apply = typename unbox_impl<lft <= 1>::template apply<lft,
            typename unbox_impl<rgt <= 1>::template apply<rgt, x>::type
        >;
    };

    template <>
    struct unbox_impl<true> {
        template <size_t n, typename x>
        struct apply;

        template <typename x>
        struct apply<0, x> { using type = x; };

        template <typename x>
        struct apply<1, x> : x { };
    };

    template <typename x, size_t n>
    struct unbox
        : unbox_impl<n == 1>::template apply<n, x>
    { };

<% end %>


template <typename f, size_t n>
struct trampoline {
    using type = trampoline;

    template <typename ...x>
    using apply = unbox<typename f::type::template apply<x...>, n>;
};


// tests
template <size_t n>
struct f {
    using type = f<n + 1>;
    static constexpr auto invocations = n;
};

template <size_t n>
struct _f {
    using type = _f;

    template <typename ...>
    using apply = f<n>;
};

template <size_t n,
    typename result = typename trampoline<_f<0>, n>::template apply<>::type,
    size_t invocations = result::invocations
>
struct test_trampoline {
    static_assert(invocations == n, "");
};

struct tests
    : test_trampoline<0>
    , test_trampoline<1>
    , test_trampoline<2>
    , test_trampoline<3>
    , test_trampoline<4>
    , test_trampoline<5>
{ };

template struct test_trampoline<      <%= env[:input] %>      >;
