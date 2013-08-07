/*!
 * @file
 * This file defines `boost::mpl11::always`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_ALWAYS_HPP
#define BOOST_MPL11_FUNCTIONAL_ALWAYS_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
    template <typename T>
    struct always : identity<T> {
        template <typename ...>
        struct apply
            : identity<T>
        { };
    };
}}}

#endif // !BOOST_MPL11_FUNCTIONAL_ALWAYS_HPP
