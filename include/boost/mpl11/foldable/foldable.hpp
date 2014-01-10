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
    struct foldr
        : Foldable<
            typename tag_of<typename Structure::type>::type
        >::template foldr_impl<
            typename F::type, typename State::type, typename Structure::type
        >
    { };

    template <typename F, typename State, typename Structure>
    struct foldl
        : Foldable<
            typename tag_of<typename Structure::type>::type
        >::template foldl_impl<
            typename F::type, typename State::type, typename Structure::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDABLE_FOLDABLE_HPP
