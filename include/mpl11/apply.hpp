/**
 * This file defines the `apply` metafunction.
 */

#ifndef MPL11_APPLY_HPP
#define MPL11_APPLY_HPP

#include <mpl11/bool.hpp>
#include <mpl11/quote.hpp>


namespace mpl11 {

template <typename ...> struct bind;

namespace apply_detail {
    template <typename Expression>
    struct parse_lambda {
        using type = Expression;
    };

    template <typename ...Placeholders>
    struct parse_lambda<bind<Placeholders...>> {
        using type = bind<Placeholders...>;
    };

    template <typename T>
    class is_metafunction {
        template <typename U> static true_ test(int, typename U::type* =0);
        template <typename> static false_ test(...);

    public:
        using type = decltype(test<T>(0));
        static bool const value = type::value;
    };

    template <typename IsMetafunction, template <typename ...> class F, typename ...Placeholders>
    struct parse_template {
        using type = bind<quote<F>, typename parse_lambda<Placeholders>::type...>;
    };

    template <template <typename ...> class F, typename ...Placeholders>
    struct parse_template<false_, F, Placeholders...> {
        using type = F<typename parse_lambda<Placeholders>::type...>;
    };

    template <template <typename ...> class F, typename ...Placeholders>
    struct parse_lambda<F<Placeholders...>>
        : parse_template<typename is_metafunction<F<Placeholders...>>::type,
            F, Placeholders...
        >
    { };
} // end namespace apply_detail

/**
 * Apply a metafunction class on the given arguments.
 */
template <typename F, typename ...Args>
struct apply
    : apply_detail::parse_lambda<F>::type::template apply<Args...>
{ };

} // end namespace mpl11

#include <mpl11/apply_pack.hpp> // For backward compatibility
#include <mpl11/bind.hpp>

#endif // !MPL11_APPLY_HPP
