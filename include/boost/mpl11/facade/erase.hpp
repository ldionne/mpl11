/*!
 * @file
 * This file defines `boost::mpl11::erase` for facades.
 */

#ifndef BOOST_MPL11_FACADE_ERASE_HPP
#define BOOST_MPL11_FACADE_ERASE_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, erase>::type>
    struct erase_impl<facade_tag<T>> {
        template <typename Sequence, typename First, typename Last>
        struct apply
            : Sequence::template erase<First, Last>
        { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_ERASE_HPP
