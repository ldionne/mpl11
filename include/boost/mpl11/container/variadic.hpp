/*!
 * @file
 * Defines `boost::mpl11::container::variadic`.
 */

#ifndef BOOST_MPL11_CONTAINER_VARIADIC_HPP
#define BOOST_MPL11_CONTAINER_VARIADIC_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 { namespace container {
    /*!
     * @ingroup containers
     */
    template <template <typename ...> class V, typename ...T>
    struct variadic
        : identity<V<T...>>
    { };
}}} // end namespace boost::mpl11::container


#include <boost/mpl11/adaptor.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
namespace variadic_detail {
    template <template <typename ...> class V>
    struct make_variadic {
        template <typename Vector>
        struct apply;

        template <template <typename ...> class Vector, typename ...T>
        struct apply<Vector<T...>>
            : identity<container::variadic<V, T...>>
        { };
    };
} // end namespace variadic_detail

template <typename Operation,
          template <typename ...> class V, typename ...T,
          typename ...Args>
struct dispatch<Operation, container::variadic<V, T...>, Args...>
    : dispatch<
        Operation,
        adaptor<variadic_detail::make_variadic<V>, container::vector<T...>>,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_VARIADIC_HPP
