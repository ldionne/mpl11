/*!
 * @file
 * Defines `boost::mpl11::as_placeholder`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_AS_PLACEHOLDER_HPP
#define BOOST_MPL11_FUNCTIONAL_AS_PLACEHOLDER_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/functional/as_placeholder_fwd.hpp>
#include <boost/mpl11/functional/is_placeholder.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct as_placeholder
        : T
    { };

    template <typename T>
    struct is_placeholder<as_placeholder<T>>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_AS_PLACEHOLDER_HPP
