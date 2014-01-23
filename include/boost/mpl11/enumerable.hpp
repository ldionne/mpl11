/*!
 * @file
 * Defines the methods of the @ref Enumerable typeclass.
 */

#ifndef BOOST_MPL11_ENUMERABLE_HPP
#define BOOST_MPL11_ENUMERABLE_HPP

#include <boost/mpl11/fwd/enumerable.hpp>

#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
    template <typename e>
    struct succ :
        Enumerable<typename datatype<typename e::type>::type>::
        template succ_impl<typename e::type>
    { };

    template <typename e>
    struct pred :
        Enumerable<typename datatype<typename e::type>::type>::
        template pred_impl<typename e::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ENUMERABLE_HPP
