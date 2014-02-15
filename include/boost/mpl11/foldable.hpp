/*!
 * @file
 * Defines the methods of the @ref Foldable typeclass.
 */

#ifndef BOOST_MPL11_FOLDABLE_HPP
#define BOOST_MPL11_FOLDABLE_HPP

#include <boost/mpl11/fwd/foldable.hpp>

#include <boost/mpl11/bool.hpp>       // required by fwd/foldable.hpp
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/functional.hpp> //
#include <boost/mpl11/logical.hpp>    //


namespace boost { namespace mpl11 {
    template <typename f, typename state, typename structure>
    struct foldr :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldr_impl<f, state, structure>
    { };

    template <typename f, typename state, typename structure>
    struct foldl :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldl_impl<f, state, structure>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDABLE_HPP
