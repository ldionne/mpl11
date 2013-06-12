/*!
 * @file
 * This file defines `boost::mpl11::value` for facades.
 */

#ifndef BOOST_MPL11_FACADE_VALUE_HPP
#define BOOST_MPL11_FACADE_VALUE_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/value.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, value>::type>
    struct value_impl<facade_tag<T>> {
        template <typename AssociativeSequence, typename Element>
        struct apply
            : AssociativeSequence::template value<Element>
        { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_VALUE_HPP
