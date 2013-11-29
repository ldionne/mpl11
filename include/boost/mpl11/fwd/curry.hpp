/*!
 * @file
 * Forward declares `boost::mpl11::curry`.
 */

#ifndef BOOST_MPL11_FWD_CURRY_HPP
#define BOOST_MPL11_FWD_CURRY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * Creates a [curried](http://en.wikipedia.org/wiki/Currying)
     * `MetafunctionClass` from a `MetafunctionClass` `F` and a
     * sequence of arguments.
     *
     * Specifically, `apply<curry<F, X...>, Args...>` is equivalent to
     * `apply<F, X..., Args...>`.
     */
    template <typename F, typename ...X>
    struct curry;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CURRY_HPP
