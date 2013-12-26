/*!
 * @file
 * Forward declares `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_FWD_COMPARABLE_HPP
#define BOOST_MPL11_FWD_COMPARABLE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup methods
     * @defgroup comparison_methods
     *
     * Methods representing C++ comparison operators.
     *
     * These methods are grouped together in the documentation because they
     * all share a common behavior. While the C++ operators they represent
     * are binary, their counterpart in this library can take two arguments
     * or more. Let `comp` be a comparison method. Then, `comp<T1, ..., Tn>`
     * is equivalent to `and_<comp<T1, T2>, comp<T2, Tn...>>`, and
     * `comp<T1, T2>` uses the usual tag dispatching technique. Also note
     * that `comp<T1, ..., Tn>` is guaranteed to be lazily evaluated.
     */

    /*!
     * @ingroup typeclasses
     * @defgroup Comparable Comparable
     *
     * The `Comparable` typeclass defines equality and inequality.
     *
     *
     * ### Methods
     * - `equal`
     * - `not_equal`
     *
     * ### Minimal complete definition
     * Either `equal` or `not_equal`.
     *
     *
     * @note
     * This typeclass is a bit special because all C++ types are implicitly
     * instances of it. For convenience, equality and inequality for
     * arbitrary types is defined in terms of `std::is_same`.
     */
    template <typename TagL, typename TagR>
    struct Comparable;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COMPARABLE_HPP
