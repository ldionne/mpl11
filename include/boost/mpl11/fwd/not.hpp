/*!
 * @file
 * Forward declares `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_FWD_NOT_HPP
#define BOOST_MPL11_FWD_NOT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Boolean `Integral` representing the logical negation (`!`) of its
     * argument.
     *
     * Its argument `F` must be a metafunction returning an `Integral`
     * datatype. Specifically, `not_<F>` is equivalent to
     * `bool_<!F::%type::value>`.
     */
    template <typename F>
    struct not_;

    template <typename F>
    using not_t = typename not_<F>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NOT_HPP
