/*!
 * @file
 * Forward declares `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_FWD_LAMBDA_HPP
#define BOOST_MPL11_FWD_LAMBDA_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Anonymous @ref MetafunctionClass with a user-provided behavior.
     *
     * When invoked with arguments `Args...`, `mpl11::lambda<F>` has
     * the following behavior:
     *
     * - Returns `F` as-is if `F` is a specialization of `mpl11::lambda`.
     *
     * - If `F` is a template specialization in the general form
     *   `M<T0, ..., Tn>`, let `R...` be the result of recursively invoking
     *   `lambda<Ti>` with `Args...`. Also, note that the result provided by
     *   any `Ti` for which `lambda<Ti>::is_multivalued` is `true` is
     *   expanded into `R...`. Then,
     *   - Returns `M<R...>::type` if `lambda<Ti>::triggers_recursive_eval`
     *     is `true` for any `Ti`.
     *   - Otherwise, returns `M<R...>`.
     *
     * - Otherwise, returns `F` as-is.
     *
     *
     * @note
     * `mpl11::lambda` can be specialized to customize its behavior. It must
     * be a valid @ref MetafunctionClass with two nested static boolean
     * constant expressions; `triggers_recursive_eval` and `is_multivalued`.
     *
     * @warning
     * `mpl11::lambda` differs severely from the original MPL.
     */
    template <typename F>
    struct lambda;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LAMBDA_HPP
