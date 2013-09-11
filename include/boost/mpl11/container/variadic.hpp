/*!
 * @file
 * Defines `boost::mpl11::container::variadic`.
 */

#ifndef BOOST_MPL11_CONTAINER_VARIADIC_HPP
#define BOOST_MPL11_CONTAINER_VARIADIC_HPP

#include <boost/mpl11/adaptor.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
namespace variadic_detail {
    template <template <typename ...> class V, typename Vector>
    struct variadic_impl;

    template <template <typename ...> class V, typename ...T>
    struct variadic_impl<V, container::vector<T...>>
        : identity<V<T...>>
    { };

    template <template <typename ...> class V>
    struct make_variadic {
        template <typename Vector>
        struct apply
            : identity<variadic_impl<V, Vector>>
        { };
    };
} // end namespace variadic_detail

template <typename Operation,
          template <typename ...> class V, typename Vector,
          typename ...Args>
struct dispatch<Operation, variadic_detail::variadic_impl<V, Vector>, Args...>
    : dispatch<
        Operation, adaptor<variadic_detail::make_variadic<V>, Vector>, Args...
    >
{ };

namespace container {
    /*!
     * @ingroup containers
     */
    template <template <typename ...> class F, typename ...T>
    using variadic = variadic_detail::variadic_impl<F, vector<T...>>;
} // end namespace container
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_VARIADIC_HPP
