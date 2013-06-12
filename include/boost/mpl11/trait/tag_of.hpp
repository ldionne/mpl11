/*!
 * @file
 * This file defines `boost::mpl11::trait::tag_of`.
 */

#ifndef BOOST_MPL11_TRAIT_TAG_OF_HPP
#define BOOST_MPL11_TRAIT_TAG_OF_HPP

namespace boost { namespace mpl11 { inline namespace v2 { namespace trait {
    template <typename T>
    struct tag_of {
        using type = typename T::mpl11::tag;
    };
}}}}

#endif // !BOOST_MPL11_TRAIT_TAG_OF_HPP
