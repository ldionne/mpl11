/*!
 * @file
 * Defines `boost::mpl11::Container::renew`.
 */

#ifndef BOOST_MPL11_CONTAINER_RENEW_HPP
#define BOOST_MPL11_CONTAINER_RENEW_HPP

#include <boost/mpl11/container/container.hpp>
#include <boost/mpl11/detail/not_implemented.hpp>


namespace boost { namespace mpl11 {
    template <typename C, typename Iterable>
    struct Container::renew
        : detail::not_implemented<renew<C, Iterable>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_RENEW_HPP
