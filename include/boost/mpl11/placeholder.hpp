/*!
 * @file
 * This file defines `boost::mpl11::placeholder`.
 */

#ifndef BOOST_MPL11_PLACEHOLDER_HPP
#define BOOST_MPL11_PLACEHOLDER_HPP

#include <boost/mpl11/at.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Key>
struct placeholder {
    template <typename ArgMap>
    struct apply
        : at<ArgMap, Key>
    { };
};
}}}

#endif // !BOOST_MPL11_PLACEHOLDER_HPP
