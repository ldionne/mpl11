/*!
 * @file
 * Defines `boost::mpl11::negate`.
 */

#ifndef BOOST_MPL11_OPERATOR_NEGATE_HPP
#define BOOST_MPL11_OPERATOR_NEGATE_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/operator/negate_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct dispatch<tag::default_<tag::negate>, T>
        : identity<
            integral_c<decltype(-T::value), -T::value>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_NEGATE_HPP
