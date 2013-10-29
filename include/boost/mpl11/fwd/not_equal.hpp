/*!
 * @file
 * Forward declares `boost::mpl11::not_equal`.
 */

#ifndef BOOST_MPL11_FWD_NOT_EQUAL_HPP
#define BOOST_MPL11_FWD_NOT_EQUAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns `T1 != T2 != ...Tn`.
     *
     *
     * @warning
     * Using this intrinsic with several arguments can be confusing. It
     * does not check whether `T1`, `T2`, ...`Tn` are all different, but
     * whether `T1` is different from `T2`, `T2` different from `T3` and
     * so on.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct not_equal;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NOT_EQUAL_HPP
