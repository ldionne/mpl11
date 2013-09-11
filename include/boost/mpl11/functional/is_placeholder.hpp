/*!
 * @file
 * Defines `boost::mpl11::is_placeholder`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_IS_PLACEHOLDER_HPP
#define BOOST_MPL11_FUNCTIONAL_IS_PLACEHOLDER_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Returns whether `T` is a @ref Placeholder.
     */
    template <typename T>
    struct is_placeholder
        : false_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_IS_PLACEHOLDER_HPP
