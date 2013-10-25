/*!
 * @file
 * Defines `boost::mpl11::AssociativeContainer::erase_key`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_CONTAINER_ERASE_KEY_HPP
#define BOOST_MPL11_ASSOCIATIVE_CONTAINER_ERASE_KEY_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/associative_container/associative_container.hpp>
#include <boost/mpl11/filtered_view.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/not_equal_to.hpp>
#include <boost/mpl11/renew.hpp>


namespace boost { namespace mpl11 {
    template <typename AC, typename Key>
    struct AssociativeContainer::erase_key
        : renew<AC,
            filtered_view<
                Sequence,
                not_equal_to<Key, key_of<Sequence, _1>>
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_CONTAINER_ERASE_KEY_HPP
