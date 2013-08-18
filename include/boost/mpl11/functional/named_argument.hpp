/*!
 * @file
 * This file defines `boost::mpl11::named_argument`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_NAMED_ARGUMENT_HPP
#define BOOST_MPL11_FUNCTIONAL_NAMED_ARGUMENT_HPP

#include <boost/mpl11/container/pair.hpp>


namespace boost { namespace mpl11 {
    template <typename Name, typename Value>
    struct named_argument : pair<Name, Value> {
        struct mpl11 : pair<Name, Value>::mpl11 {
            struct is_named_argument;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_NAMED_ARGUMENT_HPP
