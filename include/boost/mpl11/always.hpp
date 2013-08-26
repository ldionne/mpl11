/*!
 * @file
 * Defines `boost::mpl11::always`.
 */

#ifndef BOOST_MPL11_ALWAYS_HPP
#define BOOST_MPL11_ALWAYS_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Metafunction class always returning `T`, regardless of the
     * number and types of passed arguments.
     */
    template <typename T>
    struct always {
        template <typename ...>
        struct apply
            : identity<T>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALWAYS_HPP
