/*!
 * @file
 * Defines `boost::mpl11::as_placeholder`.
 */

#ifndef BOOST_MPL11_AS_PLACEHOLDER_HPP
#define BOOST_MPL11_AS_PLACEHOLDER_HPP

#include <boost/mpl11/fwd/as_placeholder.hpp>

#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct as_placeholder {
        template <typename Context, typename ...Args>
        using is_multivalued = false_;

        template <typename Context, typename ...Args>
        using triggers_evaluation = false_;

        template <typename Context, typename ...Args>
        using apply = identity<T>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AS_PLACEHOLDER_HPP
