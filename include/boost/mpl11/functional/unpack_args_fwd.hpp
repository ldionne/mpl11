/*!
 * @file
 * Forward declares `boost::mpl11::unpack_args`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_UNPACK_ARGS_FWD_HPP
#define BOOST_MPL11_FUNCTIONAL_UNPACK_ARGS_FWD_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Higher-order primitive transforming an `n`-ary @ref LambdaExpression
     * `F` into an unary @ref MetafunctionClass accepting a single sequence
     * of `n` arguments.
     */
    template <typename F>
    struct unpack_args;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_UNPACK_ARGS_FWD_HPP
