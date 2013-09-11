/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_OPERATOR_AND_HPP
#define BOOST_MPL11_OPERATOR_AND_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup logical_operators
     *
     * Returns the result of short-circuit _logical and_ (`&&`) on the result
     * of its arguments.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : dispatch<tag::and_, F1, F2, Fn...>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/and.hpp>
#endif

#endif // !BOOST_MPL11_OPERATOR_AND_HPP
