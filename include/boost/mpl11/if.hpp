/*!
 * @file
 * Defines `boost::mpl11::if_` et al.
 */

#ifndef BOOST_MPL11_IF_HPP
#define BOOST_MPL11_IF_HPP

#include <boost/mpl11/fwd/if.hpp>


namespace boost { namespace mpl11 {
    template <typename Condition, typename Then, typename Else>
    struct if_
        : if_c<static_cast<bool>(Condition::type::value), Then, Else>
    { };

    template <typename Then, typename Else>
    struct if_c<true, Then, Else> : Then { };

    template <typename Then, typename Else>
    struct if_c<false, Then, Else> : Else { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IF_HPP
