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

#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
    template <typename f, typename structure>
    struct fmap :
        Functor<typename datatype<typename structure::type>::type>::
        template fmap_impl<f, typename structure::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTOR_HPP
