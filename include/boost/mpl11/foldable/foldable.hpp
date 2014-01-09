/*!
 * @file
 * Defines the methods of the @ref Foldable typeclass.
 */

#ifndef BOOST_MPL11_FOLDABLE_FOLDABLE_HPP
#define BOOST_MPL11_FOLDABLE_FOLDABLE_HPP

#include <boost/mpl11/fwd/foldable.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename State, typename Structure>
    struct lazy_foldr_impl {
        using type = typename Foldable<typename tag_of<Structure>::type>::
                     template lazy_foldr_impl<F, State, Structure>::type;
    };

    template <typename F, typename State, typename Structure>
    struct foldr_impl {
        using type = typename Foldable<typename tag_of<Structure>::type>::
                     template foldr_impl<F, State, Structure>::type;
    };

    template <typename F, typename State, typename Structure>
    struct foldl_impl {
        using type = typename Foldable<typename tag_of<Structure>::type>::
                     template foldl_impl<F, State, Structure>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDABLE_FOLDABLE_HPP
