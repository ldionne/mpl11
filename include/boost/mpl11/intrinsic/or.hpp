/*!
 * @file
 * Defines `boost::mpl11::intrinsic::or_`.
 */

#ifndef BOOST_MPL11_INTRINSIC_OR_HPP
#define BOOST_MPL11_INTRINSIC_OR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup logical_intrinsic
     *
     * Returns the result of short-circuit _logical or_ (`||`) on the result
     * of its arguments.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : dispatch<tag::or_, F1, F2, Fn...>
    { };

    template <typename F1, typename F2>
    struct or_<F1, F2>
        : dispatch<tag::or_, F1, F2>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/or.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_OR_HPP
