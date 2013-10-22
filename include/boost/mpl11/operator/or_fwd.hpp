/*!
 * @file
 * Forward declares `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OPERATOR_OR_FWD_HPP
#define BOOST_MPL11_OPERATOR_OR_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct or_; }

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

#endif // !BOOST_MPL11_OPERATOR_OR_FWD_HPP
