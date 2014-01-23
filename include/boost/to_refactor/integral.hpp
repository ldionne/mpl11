/*!
 * @file
 * Defines `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_INTEGRAL_HPP
#define BOOST_MPL11_INTEGRAL_HPP

#include <boost/mpl11/fwd/integral.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename M, typename N>
    struct quot
        : Integral<
            typename tag_of<typename M::type>::type,
            typename tag_of<typename N::type>::type
        >::template quot_impl<typename M::type, typename N::type>
    { };

    template <typename M, typename N>
    struct rem
        : Integral<
            typename tag_of<typename M::type>::type,
            typename tag_of<typename N::type>::type
        >::template rem_impl<typename M::type, typename N::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_HPP
