/*!
 * @file
 * Forward declares `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_FWD_NOT_HPP
#define BOOST_MPL11_FWD_NOT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup logical_operators
     *
     * Returns the result of _logical not_ (`!`) on the result of its
     * metafunction argument.
     *
     * `not_` is a special intrinsic: its argument is a metafunction returning
     * a `Boolean`. This is so because it makes it easier to combine `not_`
     * with other logical operators that must ensure short-circuit evaluation.
     *
     *
     * @note
     * Custom implementations are called with `F::type` instead of `F`.
     *
     * @note
     * The result of custom implementations must be either `true_`
     * or `false_`. Returning any other type is invalid, even if
     * the returned type is a `Boolean`.
     */
    template <typename F>
    struct not_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NOT_HPP
