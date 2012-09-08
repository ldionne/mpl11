/**
 * This file defines the requires metafunction.
 */

#ifndef DUCK_REQUIRES_HPP
#define DUCK_REQUIRES_HPP

#include <duck/and.hpp>
#include <duck/pack.hpp>
#include <duck/pop_back.hpp>
#include <duck/when.hpp>


namespace duck {

/**
 * Expand to the last type in the parameter pack if all the types
 * before it are true_. Otherwise, expand to an invalid type.
 *
 * This is useful to express the concept requirements of a template
 * in its declaration, much like std::enable_if does.
 */
namespace detail {
    template <typename ...> struct requires_impl2;
    template <typename ...Concepts, typename T>
    struct requires_impl2<pack<Concepts...>, T>
        : when<typename and_<Concepts...>::type, T> { };

    template <typename AtLeastReturnType, typename ...ConceptsAndReturnType>
    struct requires_impl
        : requires_impl2<
            typename pop_back<
                AtLeastReturnType, ConceptsAndReturnType...
            >::type,
            typename back<
                AtLeastReturnType, ConceptsAndReturnType...
            >::type
        >
    { };
} // end namespace detail

// Delegate the work to a struct implementing the logic. This allows us to
// use `requires<Foo, void>` instead of `typename requires<Foo, void>::type`.
template <typename ...ConceptsAndT>
using requires = typename detail::requires_impl<ConceptsAndT...>::type;

} // end namespace duck

#endif // !DUCK_REQUIRES_HPP
