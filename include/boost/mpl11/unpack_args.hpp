/*!
 * @file
 * Defines `boost::mpl11::unpack_args`.
 */

#ifndef BOOST_MPL11_UNPACK_ARGS_HPP
#define BOOST_MPL11_UNPACK_ARGS_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/container/vector.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Higher-order primitive transforming an `n`-ary `LambdaExpression` `F`
     * into an unary `MetafunctionClass` accepting a single sequence of
     * `n` arguments.
     */
    template <typename F>
    struct unpack_args {
        template <typename Args>
        struct apply
            : apply<typename algorithm::copy<Args, container::vector<>>::type>
        { };

        template <typename ...Args>
        struct apply<container::vector<Args...>>
            : mpl11::apply<F, Args...>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_UNPACK_ARGS_HPP
