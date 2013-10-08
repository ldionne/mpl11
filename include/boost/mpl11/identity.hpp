/*!
 * @file
 * Defines `boost::mpl11::identity`.
 */

#ifndef BOOST_MPL11_IDENTITY_HPP
#define BOOST_MPL11_IDENTITY_HPP

#include <boost/mpl11/identity_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct identity {
        using type = T;
    };
}}

#endif // !BOOST_MPL11_IDENTITY_HPP
