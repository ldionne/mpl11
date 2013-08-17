/*!
 * @file
 * This file defines `boost::mpl11::named_argument`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_NAMED_ARGUMENT_HPP
#define BOOST_MPL11_FUNCTIONAL_NAMED_ARGUMENT_HPP

namespace boost { namespace mpl11 {
    template <typename Name, typename Value>
    struct named_argument {
        struct mpl11 { struct is_named_argument; };

        using key = Name;
        using value = Value;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_NAMED_ARGUMENT_HPP
