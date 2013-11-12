/*!
 * @file
 * Defines `boost::mpl11::FrontExtensibleContainer`.
 */

#ifndef BOOST_MPL11_FRONT_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_FRONT_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/front_extensible_container.hpp>

#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/container.hpp> // required by the fwd declaration
#include <boost/mpl11/push_front.hpp>


namespace boost { namespace mpl11 {
    template <typename C>
    struct FrontExtensibleContainer::new_impl {
        template <typename ...T>
        struct apply
            : clear<C>
        { };

        template <typename Head, typename ...Tail>
        struct apply<Head, Tail...>
            : push_front<typename apply<Tail...>::type, Head>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FRONT_EXTENSIBLE_CONTAINER_HPP
