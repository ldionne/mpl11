/*!
 * @file
 * Forward declares `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_LAMBDA_FWD_HPP
#define BOOST_MPL11_FUNCTIONAL_LAMBDA_FWD_HPP

namespace boost { namespace mpl11 {
/*!
 * @ingroup functional
 *
 * Transforms a @ref LambdaExpression into its corresponding
 * @ref MetafunctionClass.
 *
 * If `T` is not a @ref PlaceholderExpression, returns `T` unchanged.
 *
 * Otherwise, if `T` is a @ref Placeholder, returns a non-template
 * @ref MetafunctionClass without base class and equivalent to `T`
 * when applied.
 *
 * Otherwise, let `T` be a @ref PlaceholderExpression in a general form
 * `F<A1, A2, ...An>`, where `F` is a class template and `A1`, `A2`, ...`An`
 * are arbitrary types. The returned type is a non-template
 * @ref MetafunctionClass without base class and equivalent to
   @code
        bind<
            quote<F>,
            bind_nested<A1>::type,
            bind_nested<A2>::type,
            bind_nested<An>::type...
        >
   @endcode
 * when applied. `bind_nested` is a metafunction returning a type such that
 * any nested @ref PlaceholderExpression will be applied when the outer `bind`
 * is applied, but all other types are left unchanged.
 *
 *
 * @warning
 * Differences from the original MPL:
 * - The specification of the substitution mechanism is completely different,
 *   but most existing @ref LambdaExpression "Lambda Expressions" should
 *   work as-is.
 */
template <typename F>
struct lambda;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_LAMBDA_FWD_HPP
