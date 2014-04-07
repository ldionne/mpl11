/*!
 * @file
 * Defines the `fmap` method of the @ref Functor typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FUNCTOR_HPP
#define BOOST_MPL11_FUNCTOR_HPP

#include <boost/mpl11/fwd/functor.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/config.hpp>
#include <boost/mpl11/functional.hpp>


namespace boost { namespace mpl11 {
    template <typename Datatype, typename>
    struct Functor : false_ { };

    template <typename f, typename structure>
    struct fmap :
        Functor<typename datatype<typename structure::type>::type>::
        template fmap_impl<f, typename structure::type>
    { };

#ifndef BOOST_MPL11_NO_REWRITE_RULES
    template <typename f, typename g, typename structure>
    struct fmap<f, fmap<g, structure>>
        : fmap<compose<f, g>, structure>
    { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTOR_HPP
