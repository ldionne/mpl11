/*!
 * @file
 * Defines `boost::mpl11::id`.
 */

#ifndef BOOST_MPL11_ID_HPP
#define BOOST_MPL11_ID_HPP

#include <boost/mpl11/fwd/id.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct id {
        using type = T;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ID_HPP
