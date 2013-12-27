/*!
 * @file
 * Forward declares `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_FWD_OR_HPP
#define BOOST_MPL11_FWD_OR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Boolean `Integral` representing the result of short-circuit logical
     * or (`||`) on its arguments.
     *
     * Specifically, its arguments must be `Metafunction`s returning
     * `Integral` datatypes. Arguments are then evaluated from left
     * to right in a short-circuiting fashion. If no arguments are
     * provided, `or_` is equivalent to `false_`.
     */
    template <typename ...Fn>
    struct or_;

    template <typename ...Fn>
    using or_t = typename or_<Fn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_OR_HPP
