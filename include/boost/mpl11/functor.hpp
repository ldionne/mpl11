/*!
 * @file
 * Defines the `fmap` method of the @ref Functor typeclass.
 */

#ifndef BOOST_MPL11_FUNCTOR_HPP
#define BOOST_MPL11_FUNCTOR_HPP

#include <boost/mpl11/fwd/functor.hpp>

#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
    template <typename f, typename structure>
    struct fmap :
        Functor<typename datatype<typename structure::type>::type>::
        template fmap_impl<f, structure>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTOR_HPP
