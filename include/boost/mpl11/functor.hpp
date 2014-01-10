/*!
 * @file
 * Defines the methods of the @ref Functor typeclass.
 */

#ifndef BOOST_MPL11_FUNCTOR_HPP
#define BOOST_MPL11_FUNCTOR_HPP

#include <boost/mpl11/fwd/functor.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename function, typename functor>
    struct fmap {
        using type = typename Functor<typename tag_of<functor>::type>::
                     template fmap_impl<function, functor>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTOR_HPP
