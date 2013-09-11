/*!
 * @file
 * Defines `boost::mpl11::not_equal_to`.
 */

#ifndef BOOST_MPL11_OPERATOR_NOT_EQUAL_TO_HPP
#define BOOST_MPL11_OPERATOR_NOT_EQUAL_TO_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup comparison_operators
     *
     * Returns whether `T1 != T2 != ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * When more than two arguments are provided, as described in
     * @ref comparison_operators. Otherwise, equivalent to
     * `not_<equal_to<T1, T2>>`.
     *
     *
     * @warning
     * Using this intrinsic with several arguments can be confusing. It
     * does not check whether `T1`, `T2`, ...`Tn` are all different, but
     * whether they are different from left to right.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct not_equal_to
        : dispatch<tag::not_equal_to, T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/not_equal_to.hpp>
#endif

#endif // !BOOST_MPL11_OPERATOR_NOT_EQUAL_TO_HPP
