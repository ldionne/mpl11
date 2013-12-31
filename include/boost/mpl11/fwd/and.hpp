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
     * Specifically, its arguments must be metafunctions returning
     * `Integral` datatypes. Arguments are then evaluated from left
     * to right in a short-circuiting fashion. If no arguments are
     * provided, `and_` is equivalent to `true_`.
     */
    template <typename ...Fn>
    struct and_;

    template <typename ...Fn>
    using and_t = typename and_<Fn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AND_HPP
