/*!
 * @file
 * Forward declares `boost::mpl11::inherit`.
 */

#ifndef BOOST_MPL11_FWD_INHERIT_HPP
#define BOOST_MPL11_FWD_INHERIT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns an unspecified non-template type publicly
     * derived from `Bases...`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No special treatment is provided to `empty_base`.
     * - The result is never a simple alias to one of the `Bases...`.
     */
    template <typename ...Bases>
    struct inherit;

    template <typename ...Bases>
    struct inherit_t;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INHERIT_HPP
