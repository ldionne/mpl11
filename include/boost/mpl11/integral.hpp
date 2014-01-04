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
    struct quot_impl
        : Integral<
            typename tag_of<M>::type, typename tag_of<N>::type
        >::template quot_impl<M, N>
    { };

    template <typename M, typename N>
    struct rem_impl
        : Integral<
            typename tag_of<M>::type, typename tag_of<N>::type
        >::template rem_impl<M, N>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_HPP
