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
     * to write in a short-circuiting fashion.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_;

    template <typename F1, typename F2, typename ...Fn>
    using or_t = typename or_<F1, F2, Fn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_OR_HPP
