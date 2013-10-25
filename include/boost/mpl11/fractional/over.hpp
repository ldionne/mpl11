/*!
 * @file
 * Defines `boost::mpl11::Fractional::over`.
 */

#ifndef BOOST_MPL11_FRACTIONAL_OVER_HPP
#define BOOST_MPL11_FRACTIONAL_OVER_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/fractional/fractional.hpp>


namespace boost { namespace mpl11 {
    template <typename M, typename N>
    struct Fractional::over
        : detail::not_implemented<over<M, N>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FRACTIONAL_OVER_HPP
