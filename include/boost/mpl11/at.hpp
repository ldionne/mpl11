/*!
 * @file
 * Defines `boost::mpl11::at` and `boost::mpl11::at_c`.
 */

#ifndef BOOST_MPL11_AT_HPP
#define BOOST_MPL11_AT_HPP

#include <boost/mpl11/fwd/at.hpp>

#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/integral_c.hpp> // for at_c


namespace boost { namespace mpl11 {
    template <typename Sequence, typename N>
    struct at
        : class_of<Sequence>::type::template at_impl<Sequence, N>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AT_HPP
