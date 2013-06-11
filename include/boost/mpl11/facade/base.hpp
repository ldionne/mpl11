/*!
 * @file
 * This file defines `boost::mpl11::base_facade`.
 */

#ifndef BOOST_MPL11_FACADE_BASE_HPP
#define BOOST_MPL11_FACADE_BASE_HPP

namespace boost { namespace mpl11 { inline namespace v2 {
    template <typename Impl> struct facade_tag;

    template <typename Impl>
    struct base_facade {
        struct mpl11 { using tag = facade_tag<Impl>; };
    };
}}}

#endif // !BOOST_MPL11_FACADE_BASE_HPP
