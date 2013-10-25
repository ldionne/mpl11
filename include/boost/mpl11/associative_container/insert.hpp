/*!
 * @file
 * Defines `boost::mpl11::AssociativeContainer::insert`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_CONTAINER_INSERT_HPP
#define BOOST_MPL11_ASSOCIATIVE_CONTAINER_INSERT_HPP

#include <boost/mpl11/associative_container/associative_container.hpp>
#include <boost/mpl11/erase_key.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/renew.hpp>
#include <boost/mpl11/single_view.hpp>


namespace boost { namespace mpl11 {
    template <typename AC, typename Element>
    struct AssociativeContainer::insert
        : renew<AC,
            joined_view<
                typename erase_key<AC,
                    typename key_of<AC, Element>::type
                >::type,
                single_view<Element>
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_CONTAINER_INSERT_HPP
