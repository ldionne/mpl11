/*!
 * @file
 * Defines `boost::mpl11::BackExtensibleContainer`.
 */

#ifndef BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/back_extensible_container.hpp>

#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/container.hpp> // required by the fwd declaration
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename C>
    struct BackExtensibleContainer::new_impl {
        template <typename Sequence>
        using apply = foldl<Sequence, clear_t<C>, quote<push_back>>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
