/*!
 * @file
 * Defines `boost::mpl11::identity`.
 */

#ifndef BOOST_MPL11_IDENTITY_HPP
#define BOOST_MPL11_IDENTITY_HPP

#include <boost/mpl11/fwd/identity.hpp>

#include <boost/mpl11/metafunction.hpp>


namespace boost { namespace mpl11 {
    template <typename X>
    struct identity {
        using mpl_class = Metafunction;
        using type = X;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IDENTITY_HPP
