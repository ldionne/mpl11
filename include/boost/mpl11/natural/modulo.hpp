/*!
 * @file
 * Defines `boost::mpl11::Natural::modulo`.
 */

#ifndef BOOST_MPL11_NATURAL_MODULO_HPP
#define BOOST_MPL11_NATURAL_MODULO_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/natural/natural.hpp>


namespace boost { namespace mpl11 {
    template <typename M, typename N>
    struct Natural::modulo
        : detail::not_implemented<modulo<M, N>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NATURAL_MODULO_HPP
