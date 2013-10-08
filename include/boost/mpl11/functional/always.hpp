/*!
 * @file
 * Defines `boost::mpl11::always` and `boost::mpl11::lazy_always`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_ALWAYS_HPP
#define BOOST_MPL11_FUNCTIONAL_ALWAYS_HPP

#include <boost/mpl11/detail/either.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/functional/always_fwd.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct always {
        template <typename ...>
        struct apply
            : identity<T>
        { };
    };

    template <typename F>
    struct lazy_always {
        template <typename ...>
        struct apply
            : detail::either<F, empty_base>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_ALWAYS_HPP
