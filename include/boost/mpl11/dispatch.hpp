/*!
 * @file
 * Defines `boost::mpl11::dispatch`.
 */

#ifndef BOOST_MPL11_DISPATCH_HPP
#define BOOST_MPL11_DISPATCH_HPP

#include <boost/mpl11/fwd/dispatch.hpp>

#include <boost/mpl11/category/none.hpp>
#include <boost/mpl11/detail/dependent_on.hpp>
#include <boost/mpl11/parent.hpp>


namespace boost { namespace mpl11 {
    template <typename Operation, typename ...Args>
    struct dispatch {
        static_assert(
            detail::dependent_on<Operation>::template value<bool, false>(),
        "No default implementation is provided for the requested "
        "operation with the provided arguments.");
    };

    template <typename Operation>
    struct dispatch<tag::by_category<Operation>, category::none> {
        static_assert(
            detail::dependent_on<Operation>::template value<bool, false>(),
        "No default implementation is provided for the requested "
        "operation with the provided category.");

        template <typename ...>
        struct apply { struct type; };
    };

    template <typename Operation, typename Category>
    struct dispatch<tag::by_category<Operation>, Category>
        : dispatch<
            tag::by_category<Operation>,
            typename parent<Category>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DISPATCH_HPP
