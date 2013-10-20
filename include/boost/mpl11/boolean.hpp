/*!
 * @file
 * Defines `boost::mpl11::Boolean`.
 */

#ifndef BOOST_MPL11_BOOLEAN_HPP
#define BOOST_MPL11_BOOLEAN_HPP

#include <boost/mpl11/fwd/boolean.hpp>

// break circular dependency between Boolean and Metafunction
#include <boost/mpl11/fwd/if.hpp>
#include <boost/mpl11/object.hpp>


namespace boost { namespace mpl11 {
    // !, &&, ||, if_
    struct Boolean : Object {
        template <typename A, typename B>
        struct and_
            : if_<A, B, A>
        { };

        template <typename A, typename B>
        struct or_
            : if_<A, A, B>
        { };
    };
}} // end namespace boost::mpl11

#include <boost/mpl11/if.hpp>

#endif // !BOOST_MPL11_BOOLEAN_HPP
