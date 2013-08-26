/*!
 * @file
 * Defines `boost::mpl11::as_placeholder`.
 */

#ifndef BOOST_MPL11_AS_PLACEHOLDER_HPP
#define BOOST_MPL11_AS_PLACEHOLDER_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/is_placeholder.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Wraps an arbitrary type to make it into a placeholder.
     *
     * Specifically, `as_placeholder<T>` is a type publically derived from
     * `T` for which the `is_placeholder` metafunction returns `true_`.
     */
    template <typename T>
    struct as_placeholder
        : T
    { };

    template <typename T>
    struct is_placeholder<as_placeholder<T>>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AS_PLACEHOLDER_HPP
