/*!
 * @file
 * Defines `boost::mpl11::negate`.
 */

#ifndef BOOST_MPL11_NEGATE_HPP
#define BOOST_MPL11_NEGATE_HPP

#include <boost/mpl11/fwd/negate.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Integral>
    struct negate
        : class_<Integral>::type::template negate<Integral>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NEGATE_HPP
