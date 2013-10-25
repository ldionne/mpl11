/*!
 * @file
 * Defines `boost::mpl11::Natural::times`.
 */

#ifndef BOOST_MPL11_NATURAL_TIMES_HPP
#define BOOST_MPL11_NATURAL_TIMES_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/natural/natural.hpp>


namespace boost { namespace mpl11 {
    template <typename M, typename N>
    struct Natural::times
        : detail::not_implemented<times<M, N>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NATURAL_TIMES_HPP
