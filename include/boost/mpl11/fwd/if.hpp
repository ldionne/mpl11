/*!
 * @file
 * Forward declares `boost::mpl11::if_`.
 */

#ifndef BOOST_MPL11_FWD_IF_HPP
#define BOOST_MPL11_FWD_IF_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Select one of two types based on an `StaticConstant` condition.
     *
     * Specifically, `Condition` must be a metafunction returning a
     * `StaticConstant`. If `Condition::type::value` is `true`, `Then`
     * is returned. Otherwise, `Else` is returned.
     */
    template <typename Condition, typename Then, typename Else>
    struct if_;

    template <typename Condition, typename Then, typename Else>
    using if_t = typename if_<Condition, Then, Else>::type;

    /*!
     * @ingroup metafunctions
     *
     * Alias to `if_<bool_<Condition>, Then, Else>`; provided for convenience.
     */
    template <bool Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(if_c, if_<bool_<Condition>, Then, Else>);

    template <bool Condition, typename Then, typename Else>
    using if_c_t = typename if_<bool_<Condition>, Then, Else>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IF_HPP
