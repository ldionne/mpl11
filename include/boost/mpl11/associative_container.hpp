/*!
 * @file
 * Defines `boost::mpl11::AssociativeContainer`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_CONTAINER_HPP
#define BOOST_MPL11_ASSOCIATIVE_CONTAINER_HPP

#include <boost/mpl11/fwd/associative_container.hpp>

#include <boost/mpl11/container.hpp> // required by the forward declaration
#include <boost/mpl11/erase_key.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/insert_key.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename C, typename Elements>
    struct AssociativeContainer::insert_keys_impl
        : foldl<Elements, C, quote<insert_key>>
    { };

    template <typename C, typename Keys>
    struct AssociativeContainer::erase_keys_impl
        : foldl<Keys, C, quote<erase_key>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_CONTAINER_HPP
