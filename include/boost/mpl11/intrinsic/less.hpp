/*!
 * @file
 * Defines `boost::mpl11::intrinsic::less`.
 */

#ifndef BOOST_MPL11_INTRINSIC_LESS_HPP
#define BOOST_MPL11_INTRINSIC_LESS_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 < T2 < ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct less BOOST_MPL11_DOXYGEN_ONLY(<T1, T2, Tn...>)
        : dispatch<tag::less, T1, T2, Tn...>
    { };

    /*!
     * @ingroup comparison_intrinsic
     *
     * Returns whether `T1 < T2`.
     *
     *
     * ### Default implementation
     *
     * Equivalent to `identity<bool_<T1::value < T2::value>>` if `T1`
     * and `T2` are @ref IntegralConstant "Integral Constants", and
     * not provided otherwise.
     */
    template <typename T1, typename T2>
    struct less<T1, T2>
        : dispatch<tag::less, T1, T2>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/less.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_LESS_HPP
