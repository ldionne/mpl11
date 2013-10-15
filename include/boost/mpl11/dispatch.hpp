/*!
 * @file
 * Defines `boost::mpl11::dispatch`.
 */

#ifndef BOOST_MPL11_DISPATCH_HPP
#define BOOST_MPL11_DISPATCH_HPP

#include <boost/mpl11/fwd/dispatch.hpp>

#include <boost/mpl11/detail/dependent_on.hpp>


namespace boost { namespace mpl11 {
    // Raw type dispatching
    template <typename Operation, typename ...Args>
    struct dispatch {
        static_assert(
            detail::dependent_on<Operation>::template value<bool, false>(),
        "No default implementation is provided for the requested "
        "operation with the provided arguments.");

        struct type;
    };

    // Single category dispatching
    template <typename Operation, typename Category>
    struct dispatch<tag::single<Operation>, Category> {
        static_assert(
            detail::dependent_on<Operation>::template value<bool, false>(),
        "No default implementation is provided for the requested "
        "operation with the provided category.");

        template <typename ...>
        struct apply { struct type; };
    };

    // Dual category dispatching
    template <typename Operation, typename Category1, typename Category2>
    struct dispatch<tag::dual<Operation>, Category1, Category2> {
        static_assert(
            detail::dependent_on<Operation>::template value<bool, false>(),
        "No default implementation is provided for the requested "
        "operation with the provided categories.");

        template <typename ...>
        struct apply { struct type; };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DISPATCH_HPP
