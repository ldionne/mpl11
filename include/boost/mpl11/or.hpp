/*!
 * @file
 * Defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OR_HPP
#define BOOST_MPL11_OR_HPP

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Returns the result of short-circuit _logical or_ on its arguments.
     *
     * Returns `true_` if either `F1::type::value`, `F2::type::value`, or
     * `Fn::type::value...` evaluates to `true`, and `false_` otherwise.
     * Lazy left-to-right evaluation is guaranteed.
     *
     * @tparam F1, F2, Fn...
     *         Nullary boolean metafunctions that are lazily evaluated from
     *         left to right.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : not_<
            and_<
                not_<F1>, not_<F2>, not_<Fn>...
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OR_HPP
