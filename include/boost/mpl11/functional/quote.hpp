/*!
 * @file
 * This file defines `boost::mpl11::quote`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_QUOTE_HPP
#define BOOST_MPL11_FUNCTIONAL_QUOTE_HPP

namespace boost { namespace mpl11 {
    template <template <typename ...> class M>
    struct quote {
        template <typename ...Args>
        struct apply
            : M<Args...>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_QUOTE_HPP
