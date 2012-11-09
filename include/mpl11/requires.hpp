/**
 * This file defines the requires metafunction.
 */

#ifndef MPL11_REQUIRES_HPP
#define MPL11_REQUIRES_HPP

#include <mpl11/all_of.hpp>
#include <mpl11/apply.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/quote.hpp>
#include <mpl11/rotate_right.hpp>
#include <mpl11/when.hpp>

namespace mpl11 {

/**
 * Expand to the last type in the parameter pack if all the types before it
 * are `true_`. Otherwise, expand to an invalid type.
 *
 * This is useful to express the concept requirements of a template
 * in its declaration, much like std::enable_if does.
 */
namespace detail {
    template <typename T, typename ...Concepts>
    struct requires_impl
        : when<
            typename all_of<quote<identity>, Concepts...>::type, T
        >
    { };
}

template <typename ...ConceptsAndT>
struct requires
    : apply_pack<
        quote<detail::requires_impl>,
        typename rotate_right<ConceptsAndT...>::type
    >
{ };

} // end namespace mpl11

#endif // !MPL11_REQUIRES_HPP
