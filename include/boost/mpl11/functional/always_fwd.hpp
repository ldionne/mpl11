/*!
 * @file
 * Forward declares `boost::mpl11::always` and `boost::mpl11::lazy_always`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_ALWAYS_FWD_HPP
#define BOOST_MPL11_FUNCTIONAL_ALWAYS_FWD_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Metafunction class always returning `T`, regardless of the
     * number and types of passed arguments.
     */
    template <typename T>
    struct always;

    /*!
     * @ingroup functional
     *
     * Metafunction class always returning `F::type` if it is a valid
     * expression, regardless of the number and types of passed arguments.
     *
     * If `F::type` is not a valid expression, `lazy_always<F>::apply<...>`
     * does not have a nested type.
     */
    template <typename F>
    struct lazy_always;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_ALWAYS_FWD_HPP
