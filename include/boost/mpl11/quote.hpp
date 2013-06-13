/*!
 * @file
 * This file defines `boost::mpl11::quote`.
 */

#ifndef BOOST_MPL11_QUOTE_HPP
#define BOOST_MPL11_QUOTE_HPP

namespace boost { namespace mpl11 { inline namespace v2 {
    template <template <typename ...> class M>
    struct quote {
        template <typename ...Args>
        struct apply
            : M<Args...>
        { };
    };
}}}

#endif // !BOOST_MPL11_QUOTE_HPP
