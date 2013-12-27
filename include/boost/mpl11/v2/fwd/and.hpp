/*!
 * @file
 * Forward declares `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_FWD_AND_HPP
#define BOOST_MPL11_FWD_AND_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Boolean `Integral` representing the result of short-circuit logical
     * and (`&&`) on its arguments.
     *
     * Specifically, its arguments must be `Metafunction`s returning
     * `Integral` datatypes. Arguments are then evaluated from left
     * to write in a short-circuiting fashion.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct and_;

    template <typename F1, typename F2, typename ...Fn>
    using and_t = typename and_<F1, F2, Fn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AND_HPP
