/*!
 * @file
 * Defines `boost::mpl11::insert_keys`.
 */

#ifndef BOOST_MPL11_INSERT_KEYS_HPP
#define BOOST_MPL11_INSERT_KEYS_HPP

#include <boost/mpl11/fwd/insert_keys.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Elements>
    struct insert_keys
        : class_of<Container>::type::template
            insert_keys_impl<Container, Elements>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_KEYS_HPP
