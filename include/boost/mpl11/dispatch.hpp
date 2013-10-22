/*!
 * @file
 * Defines `boost::mpl11::dispatch`.
 */

#ifndef BOOST_MPL11_DISPATCH_HPP
#define BOOST_MPL11_DISPATCH_HPP

#include <boost/mpl11/detail/dependent_on.hpp>


namespace boost { namespace mpl11 {
    namespace tag { template <typename Operation> struct default_; }

    template <typename Operation, typename ...Args>
    struct dispatch
        : dispatch<tag::default_<Operation>, Args...>
    { };

    template <typename Operation, typename ...Args>
    struct dispatch<tag::default_<Operation>, Args...> {
        static_assert(
            detail::dependent_on<Operation>::template value<bool, false>(),
            "No default implementation is provided for the requested "
            "operation with the provided arguments."
        );
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DISPATCH_HPP
