/*!
 * @file
 * Defines `boost::mpl11::inherit`.
 */

#ifndef BOOST_MPL11_INHERIT_HPP
#define BOOST_MPL11_INHERIT_HPP

namespace boost { namespace mpl11 {
    /*!
     * Returns an unspecified non-template type publically
     * derived from `Bases...`.
     *
     * @warning
     * Differences from the original MPL:
     * - No special treatment is provided to `empty_base`.
     * - The result is never a simple alias to one of the `Bases...`.
     */
    template <typename ...Bases>
    struct inherit {
        struct type
            : Bases...
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INHERIT_HPP
