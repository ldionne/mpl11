/*!
 * @file
 * Forward declares `boost::mpl11::if_` and defines `boost::mpl11::if_c`.
 */

#ifndef BOOST_MPL11_FWD_IF_HPP
#define BOOST_MPL11_FWD_IF_HPP

#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Select one of two types based on a `Boolean` condition.
     *
     * If `not_<identity<Condition>>::type` is `false_`, `Then` is returned.
     * Otherwise, `Else` is returned.
     */
    template <typename Condition, typename Then, typename Else>
    struct if_;

    //! @ingroup metafunctions
    //! Alias to `if_<bool_<Condition>, Then, Else>`; provided for convenience.
    template <bool Condition, typename Then, typename Else>
    using if_c = if_<bool_<Condition>, Then, Else>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IF_HPP
