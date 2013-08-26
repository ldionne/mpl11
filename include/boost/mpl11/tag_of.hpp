/*!
 * @file
 * Defines `boost::mpl11::tag_of`.
 */

#ifndef BOOST_MPL11_TAG_OF_HPP
#define BOOST_MPL11_TAG_OF_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct tag_of
        : identity<T>
    { };
}}

#endif // !BOOST_MPL11_TAG_OF_HPP
