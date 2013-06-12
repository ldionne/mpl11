/*!
 * @file
 * This file defines `boost::mpl11::prior` for facades.
 */

#ifndef BOOST_MPL11_FACADE_PRIOR_HPP
#define BOOST_MPL11_FACADE_PRIOR_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, prior>::type>
    struct prior_impl<facade_tag<T>> {
        template <typename Iterator>
        struct apply : Iterator::prior { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_PRIOR_HPP
