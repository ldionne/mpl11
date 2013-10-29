/*!
 * @file
 * Forward declares `boost::mpl11::if_` and defines `boost::mpl11::if_c`.
 */

#ifndef BOOST_FWD_MPL11_IF_HPP
#define BOOST_FWD_MPL11_IF_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup metafunctions
     *
     * Select one of several types based on a `Boolean` condition.
     *
     *
     * `if<Condition>` has a behavior equivalent to that of `std::enable_if`.
     * A nested `type` identical to `void` is provided only iff `Condition`
     * has a `true` truth value.
     *
     * `if<Condition, Then>` is equivalent to
     *
     */
    template <typename Condition, typename Then, typename Else>
    struct if_;
#endif

    template <typename, typename = detail::optional, typename = detail::optional>
    struct if_;

    //! Equivalent to `std::conditional<Cond::type::value, Then, Else>`.
    template <typename Cond, typename Then, typename Else>
    struct if_ BOOST_MPL11_DOXYGEN_ONLY(<Cond, Then, Else>);

    //! @todo Explain features
    template <typename Cond, typename Then>
    struct if_<Cond, Then>;

    //! @ingroup metafunctions
    //! Alias to `if_<bool_<Condition>, Then, Else>`; provided for convenience.
    template <
        bool Condition,
        typename Then = detail::optional,
        typename Else = detail::optional
    >
    using if_c = if_<bool_<Condition>, Then, Else>;
}} // end namespace boost::mpl11

#endif // !BOOST_FWD_MPL11_IF_HPP
