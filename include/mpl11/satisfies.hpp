/**
 * This file defines the satisfies metafunction.
 */

#ifndef MPL11_SATISFIES_HPP
#define MPL11_SATISFIES_HPP

#include <mpl11/all_of.hpp>
#include <mpl11/apply.hpp>
#include <mpl11/bind.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/quote.hpp>
#include <mpl11/rotate_right.hpp>


namespace mpl11 {

/**
 * Determine whether a type satisfies a sequence of concepts
 * in the form of metafunction classes.
 */
namespace detail {
    template <typename T, typename ...Concepts>
    struct satisfies_impl
        : all_of<
            bind<_1, T>,
            Concepts...
        >
    { };
}
template <typename ...ConceptsAndT>
struct satisfies
    : apply_pack<
        quote<detail::satisfies_impl>,
        typename rotate_right<ConceptsAndT...>::type
    >
{ };

} // end namespace mpl11

#endif // !MPL11_SATISFIES_HPP
