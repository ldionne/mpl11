/*!
 * @file
 * Defines `boost::mpl11::BackExtensibleContainer`.
 */

#ifndef BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/back_extensible_container.hpp>

#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/container.hpp> // required by the fwd declaration
#include <boost/mpl11/push_back.hpp>


namespace boost { namespace mpl11 {
    namespace back_extensible_container_detail {
        template <typename C, typename ...T>
        struct foldl_push_back;

        template <typename C>
        struct foldl_push_back<C> {
            using type = C;
        };

        template <typename C, typename Head, typename ...Tail>
        struct foldl_push_back<C, Head, Tail...>
            : foldl_push_back<typename push_back<C, Head>::type, Tail...>
        { };
    } // end namespace back_extensible_container_detail

    template <typename C>
    struct BackExtensibleContainer::new_impl {
        template <typename ...T>
        struct apply
            : back_extensible_container_detail::foldl_push_back<
                typename clear<C>::type, T...
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
