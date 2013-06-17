/*!
 * @file
 * This file defines `boost::mpl11::protect`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_PROTECT_HPP
#define BOOST_MPL11_FUNCTIONAL_PROTECT_HPP

namespace boost { namespace mpl11 { inline namespace v2 {
    template <typename M>
    struct protect : M { };
}}}

#endif // !BOOST_MPL11_FUNCTIONAL_PROTECT_HPP
