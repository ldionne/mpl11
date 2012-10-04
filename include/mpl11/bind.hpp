/**
 * This file defines the bind metafunction.
 */

#ifndef MPL11_BIND_HPP
#define MPL11_BIND_HPP

#include <mpl11/apply.hpp>
#include <mpl11/arg.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/transform.hpp>

#include <cstddef>


namespace mpl11 {

/**
 * Create a bind expression consisting of zero or more placeholders.
 * The bind expression is a metafunction class which replaces the
 * placeholders with the rightful values when applied.
 */
template <typename ...Placeholders>
struct bind {
private:
    template <typename ...Args>
    struct replace_placeholders_with {

        // When an argument is not a placeholder, substitute it for itself.
        template <typename NotPlaceholder>
        struct apply { using type = NotPlaceholder; };

        // When an argument is a placeholder, substitute it for the
        // argument at the placeholder's index in the arguments.
        template <std::size_t n>
        struct apply<placeholder<n>> : ::mpl11::apply<arg<n>, Args...> { };

        // Catch recursive bind expressions and evaluate them.
        template <typename ...Placeholders_>
        struct apply<bind<Placeholders_...>>
            : ::mpl11::apply<bind<Placeholders_...>, Args...> { };
    };

    // Given a pack consisting of the replaced placeholders, extract the
    // metafunction class (the first parameter) and apply the arguments to it.
    template <typename Pack> struct extract_metafunc_class_and_apply;
    template <typename MetafuncClass, typename ...Args>
    struct extract_metafunc_class_and_apply<pack<MetafuncClass, Args...>>
        : ::mpl11::apply<MetafuncClass, Args...> { };

public:
    template <typename ...Args>
    struct apply
        : extract_metafunc_class_and_apply<
            typename transform<
                replace_placeholders_with<Args...>,
                Placeholders...
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
