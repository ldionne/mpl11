/*!
 * @file
 * Defines `boost::mpl11::unpack_args`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_UNPACK_ARGS_HPP
#define BOOST_MPL11_FUNCTIONAL_UNPACK_ARGS_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/container/variadic.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/unpack_args_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename F>
    struct unpack_args {
        template <typename Args>
        struct apply
            : algorithm::copy<
                Args, container::variadic<mpl11::apply, F>
            >::type
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_UNPACK_ARGS_HPP
