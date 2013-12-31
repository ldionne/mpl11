/*!
 * @file
 * Defines @ref BOOST_MPL11_CHECK_USAGE and
 * `boost::mpl11::detail::check_usage`.
 */

#ifndef BOOST_MPL11_DETAIL_CHECK_USAGE_HPP
#define BOOST_MPL11_DETAIL_CHECK_USAGE_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Macro expanding to `check_usage`.
     *
     * We use a macro because we might provide an option allowing this
     * functionality to be disabled.
     */
#define BOOST_MPL11_CHECK_USAGE(...) \
     ::boost::mpl11::detail::check_usage<__VA_ARGS__>

    /*!
     * @ingroup details
     *
     * Type checking the usage of the method invocation represented by the
     * given expression when it is instantiated.
     */
    template <typename Expr>
    struct check_usage;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_CHECK_USAGE_HPP
