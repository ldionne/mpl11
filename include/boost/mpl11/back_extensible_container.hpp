/*!
 * @file
 * Defines `boost::mpl11::BackExtensibleContainer`.
 */

#ifndef BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
#define BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP

#include <boost/mpl11/fwd/back_extensible_container.hpp>

#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/container.hpp>
#include <boost/mpl11/push_back.hpp>


namespace boost { namespace mpl11 {
    struct BackExtensibleContainer : Container {
        //! This operation must be provided by the user.
        template <typename Seq>
        struct pop_back_impl;

        //! This operation must be provided by the user.
        template <typename Seq, typename T>
        struct push_back_impl;

    private:
        template <typename Seq, typename ...T>
        struct foldl_push_back;

        template <typename Seq>
        struct foldl_push_back<Seq> {
            using type = Seq;
        };

        template <typename Seq, typename Head, typename ...Tail>
        struct foldl_push_back<Seq, Head, Tail...>
            : foldl_push_back<typename push_back<Seq, Head>::type, Tail...>
        { };

    public:
        /*!
         * Uses `push_back` repeatedly on `clear<Seq>::type` to create a new
         * container.
         */
        template <typename Seq>
        struct new_impl {
            template <typename ...T>
            struct apply
                : foldl_push_back<typename clear<Seq>::type, T...>
            { };
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_EXTENSIBLE_CONTAINER_HPP
