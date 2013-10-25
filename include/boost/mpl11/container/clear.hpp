/*!
 * @file
 * Defines `boost::mpl11::Container::clear`.
 */

#ifndef BOOST_MPL11_CONTAINER_CLEAR_HPP
#define BOOST_MPL11_CONTAINER_CLEAR_HPP

#include <boost/mpl11/container/container.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/renew.hpp>


namespace boost { namespace mpl11 {
    template <typename C>
    struct Container::clear
        : renew<C, empty_sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_CLEAR_HPP
