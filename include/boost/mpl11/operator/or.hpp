/*!
 * @file
 * Defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OPERATOR_OR_HPP
#define BOOST_MPL11_OPERATOR_OR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup logical_operators
     *
     * Returns the result of short-circuit _logical or_ (`||`) on the result
     * of its arguments.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : dispatch<tag::or_, F1, F2, Fn...>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/or.hpp>
#endif

#endif // !BOOST_MPL11_OPERATOR_OR_HPP
