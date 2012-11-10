/**
 * This file defines the bind metafunction.
 */

#ifndef MPL11_BIND_HPP
#define MPL11_BIND_HPP

#include <mpl11/apply.hpp>
#include <mpl11/arg.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/placeholders.hpp>

#include <cstddef>


namespace mpl11 {

template <typename ...Placeholders> struct bind;

namespace detail {
    template <typename Placeholders, typename Args>
    class replace_placeholders;

    /**
     * Replace the placeholders in a pack of types by the argument(s) at the
     * corresponding position in a pack of arguments.
     */
    template <typename ...Placeholders, typename ...Args>
    class replace_placeholders<pack<Placeholders...>, pack<Args...>> {

        // When a type is not a placeholder, substitute it for itself.
        // Note: The Dummy type is to allow "explicit" specialization in
        //       class scope.
        template <typename Placeholder, typename Dummy=void>
        struct replace_one
            : pack<Placeholder>
        { };

        // When a type is a placeholder, substitute it for the argument at
        // the placeholder's index in the arguments.
        template <std::size_t n, typename Dummy>
        struct replace_one<placeholder<n>, Dummy>
            : pack<typename apply<arg<n>, Args...>::type>
        { };

        // When a type is the special `_all` placeholder, replace
        // it by all the arguments.
        template <typename Dummy>
        struct replace_one<_all, Dummy>
            : pack<Args...>
        { };

        // Catch recursive bind expressions and evaluate them.
        template <typename ...NestedPlaceholders, typename Dummy>
        struct replace_one<bind<NestedPlaceholders...>, Dummy>
            : pack<
                typename apply<bind<NestedPlaceholders...>, Args...>::type
            >
        { };

        // Concatenate two variadic argument packs.
        template <typename Pack, typename ...T> struct concat_packs;
        template <typename ...T, typename ...U>
        struct concat_packs<pack<T...>, pack<U...>>
            : pack<T..., U...>
        { };

        template <typename ...T> struct replace_impl : pack<> { };

        // Recursively concatenate the result of replacing the placeholders.
        template <typename Placeholder, typename ...Rest>
        struct replace_impl<Placeholder, Rest...>
            : concat_packs<
                typename replace_one<Placeholder>::type,
                typename replace_impl<Rest...>::type
            >
        { };

    public:
        using type = typename replace_impl<Placeholders...>::type;
    };
} // end namespace detail

/**
 * Create a bind expression consisting of zero or more placeholders.
 * The bind expression is a metafunction class which replaces the
 * placeholders with the rightful values when applied.
 */
template <typename ...Placeholders>
struct bind {
private:
    // Given a pack consisting of the replaced placeholders, extract the
    // metafunction class (the first parameter) and apply the arguments to it.
    template <typename Pack> struct extract_metafunc_class_and_apply;
    template <typename MetafuncClass, typename ...Args>
    struct extract_metafunc_class_and_apply<pack<MetafuncClass, Args...>>
        : ::mpl11::apply<MetafuncClass, Args...>
    { };

public:
    template <typename ...Args>
    struct apply
        : extract_metafunc_class_and_apply<
            typename detail::replace_placeholders<
                pack<Placeholders...>, pack<Args...>
            >::type
        >
    { };
};

namespace detail {
    template <typename Pack> struct bind_pack_impl;
    template <typename ...Placeholders>
    struct bind_pack_impl<pack<Placeholders...>> {
        using type = bind<Placeholders...>;
    };
} // end namespace detail

/**
 * Equivalent to bind, but retrieve the placeholders from a pack.
 */
template <typename Pack>
using bind_pack = typename detail::bind_pack_impl<Pack>::type;

} // end namespace mpl11

#endif // !MPL11_BIND_HPP
