/*!
 * @file
 * Forward declares `boost::mpl11::negate`.
 */

#ifndef BOOST_MPL11_FWD_NEGATE_HPP
#define BOOST_MPL11_FWD_NEGATE_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct negate; }

    template <typename T>
    struct negate
        : dispatch<tag::negate, T>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns the additive inverse of an @ref IntegralConstant.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<integral_c<decltype(-T::value), -T::value>>`.
     */
    template <>
    struct negate<IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NEGATE_HPP
