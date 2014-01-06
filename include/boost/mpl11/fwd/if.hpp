/*!
 * @file
 * Forward declares `boost::mpl11::if_`.
 */

#ifndef BOOST_MPL11_FWD_IF_HPP
#define BOOST_MPL11_FWD_IF_HPP

#include <boost/mpl11/detail/doxygen.hpp>


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

    /*!
     * @ingroup metafunctions
     *
     * Equivalent to `if_<bool_<Condition>, Then, Else>`.
     */
    template <bool Condition, typename Then, typename Else>
    struct if_c;

    namespace if_detail { template <bool Condition> struct if_impl; }

    template <typename Condition, typename Then, typename Else>
    using if_t = typename if_detail::if_impl<Condition::type::value>::
                 template result<Then, Else>;

    template <bool Condition, typename Then, typename Else>
    using if_c_t = typename if_detail::if_impl<Condition>::
                   template result<Then, Else>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IF_HPP
