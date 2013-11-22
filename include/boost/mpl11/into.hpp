/*!
 * @file
 * Defines `boost::mpl11::into`.
 */

#ifndef BOOST_MPL11_INTO_HPP
#define BOOST_MPL11_INTO_HPP

#include <boost/mpl11/fwd/into.hpp>

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <template <typename ...> class Template>
    struct into {
        template <typename ...T>
        using apply = identity<Template<T...>>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTO_HPP
