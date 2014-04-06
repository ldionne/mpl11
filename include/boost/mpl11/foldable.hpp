/*!
 * @file
 * Defines the methods of the @ref Foldable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FOLDABLE_HPP
#define BOOST_MPL11_FOLDABLE_HPP

#include <boost/mpl11/fwd/foldable.hpp>

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/bool.hpp>       //
#include <boost/mpl11/functional.hpp> // required by fwd/foldable.hpp
#include <boost/mpl11/logical.hpp>    //


namespace boost { namespace mpl11 {
    template <typename Datatype, typename>
    struct Foldable : false_ { };

    template <typename f, typename state, typename structure>
    struct foldr :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldr_impl<f, state, typename structure::type>
    { };

    template <typename f, typename state, typename structure>
    struct foldl :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldl_impl<f, state, typename structure::type>
    { };

    template <typename f, typename structure>
    struct foldr1 :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldr1_impl<f, typename structure::type>
    { };

    template <typename f, typename structure>
    struct foldl1 :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldl1_impl<f, typename structure::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDABLE_HPP
