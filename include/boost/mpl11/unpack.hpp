/*!
 * @file
 * Defines `boost::mpl11::unpack`.
 */

#ifndef BOOST_MPL11_UNPACK_HPP
#define BOOST_MPL11_UNPACK_HPP

#include <boost/mpl11/fwd/unpack.hpp>

#include <boost/mpl11/detail/default_unpack.hpp>


namespace boost { namespace mpl11 {
    template <typename S, typename F>
    struct unpack
        : detail::default_unpack<S, F>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_UNPACK_HPP
