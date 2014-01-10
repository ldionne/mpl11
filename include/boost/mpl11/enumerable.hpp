/*!
 * @file
 * Defines `boost::mpl11::Enumerable`.
 */

#ifndef BOOST_MPL11_ENUMERABLE_HPP
#define BOOST_MPL11_ENUMERABLE_HPP

#include <boost/mpl11/fwd/enumerable.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename E>
    struct succ
        : Enumerable<typename tag_of<typename E::type>::type>::
          template succ_impl<typename E::type>
    { };

    template <typename E>
    struct pred
        : Enumerable<typename tag_of<typename E::type>::type>::
          template pred_impl<typename E::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ENUMERABLE_HPP
