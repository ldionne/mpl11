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
     * Boolean `Integral` representing the logical negation of `F::type`.
     *
     *
     * @note
     * Custom implementations are called with `F::type` instead of `F`.
     */
    template <typename F>
    struct not_;

    template <typename F>
    using not_t = typename not_<F>::type;

    /*!
     * @ingroup metafunctions
     *
     * Returns `!B`.
     */
    template <bool B>
    struct not_c;

    template <bool B>
    using not_c_t = typename not_c<B>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NOT_HPP
