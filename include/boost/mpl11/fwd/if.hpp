/*!
 * @file
 * Forward declares `boost::mpl11::if_`, `boost::mpl11::else_if` and
 * `boost::mpl11::else_`.
 */

#ifndef BOOST_MPL11_FWD_IF_HPP
#define BOOST_MPL11_FWD_IF_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    //! @ingroup metafunctions
    //! Equivalent to `if_<bool_<Condition>, Then, Else>`.
    template <bool Condition, typename Then, typename Else>
    struct if_c;

    template <bool Condition, typename Then, typename Else>
    using if_c_t = typename if_c<Condition, Then, Else>::type;


    //! @ingroup metafunctions
    //! Equivalent to `else_if<bool_<Condition>, Then, Else>`.
    template <bool Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_if_c, if_c<Condition, Then, Else>);

    template <bool Condition, typename Then, typename Else>
    using else_if_c_t = typename if_c<Condition, Then, Else>::type;


    /*!
     * @ingroup metafunctions
     *
     * Evaluate one of two metafunctions based on a lazy condition.
     *
     * Specifically, `Condition` must be a nullary metafunction returning
     * a `StaticConstant`. If `Condition::type::value` is `true`, `if_`
     * inherits from `Then`, otherwise it inherits from `Else`.
     *
     * `if_` can be combined with `else_if` and `else_` to form a small DSL
     * that greatly improves readability.
     */
    template <typename Condition, typename Then, typename Else>
    struct if_;

    template <typename Condition, typename Then, typename Else>
    using if_t = typename if_c<
        static_cast<bool>(Condition::type::value), Then, Else
    >::type;


    //! @ingroup metafunctions
    //! Alias to `if_`; provided for the added semantics when used with `if_`.
    template <typename Condition, typename Then, typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_if, if_<Condition, Then, Else>);

    template <typename Condition, typename Then, typename Else>
    using else_if_t = typename if_c<
        static_cast<bool>(Condition::type::value), Then, Else
    >::type;


    //! @ingroup metafunctions
    //! Transparent alias to its argument; provided for use with `if_`.
    template <typename Else>
    BOOST_MPL11_DOXYGEN_ALIAS(else_, Else);

    template <typename Else>
    using else_t = typename Else::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IF_HPP
