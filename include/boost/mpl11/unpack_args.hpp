/*!
 * @file
 * Defines `boost::mpl11::unpack_args`.
 */

#ifndef BOOST_MPL11_UNPACK_ARGS_HPP
#define BOOST_MPL11_UNPACK_ARGS_HPP

#include <boost/mpl11/fwd/unpack_args.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/copy.hpp>
#include <boost/mpl11/variadic.hpp>


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

#endif // !BOOST_MPL11_UNPACK_ARGS_HPP
