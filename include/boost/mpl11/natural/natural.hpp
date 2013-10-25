/*!
 * @file
 * Defines `boost::mpl11::Natural`.
 */

#ifndef BOOST_MPL11_NATURAL_NATURAL_HPP
#define BOOST_MPL11_NATURAL_NATURAL_HPP

#include <boost/mpl11/fwd/natural.hpp>

#include <boost/mpl11/orderable/orderable.hpp>


namespace boost { namespace mpl11 {
    struct Natural : Comparable {
        template <typename M, typename N>
        struct plus;

        template <typename M, typename N>
        struct times;

        template <typename M, typename N>
        struct modulo;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NATURAL_NATURAL_HPP
