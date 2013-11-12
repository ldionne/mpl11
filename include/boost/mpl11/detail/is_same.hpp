/*!
 * @file
 * Defines `boost::mpl11::detail::is_same`.
 */

#ifndef BOOST_MPL11_DETAIL_IS_SAME_HPP
#define BOOST_MPL11_DETAIL_IS_SAME_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns whether two types are identical.
     */
    template <typename T, typename U>
    struct is_same;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename T, typename U>
    struct is_same
        : false_
    { };

    template <typename T>
    struct is_same<T, T>
        : true_
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_IS_SAME_HPP
