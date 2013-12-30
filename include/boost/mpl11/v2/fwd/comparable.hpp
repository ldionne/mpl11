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
     * `equal` and `not_equal`.
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
    template <typename TagL, typename TagR = TagL>
    struct Comparable;

    /*!
     * @ingroup Comparable
     * @ingroup comparison_methods
     * @{
     *
     * Boolean `Integral` representing whether the given objects are equal.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct equal;

    template <typename T1, typename T2, typename ...Tn>
    using equal_t = typename equal<T1, T2, Tn...>::type;

    /*!
     * Boolean `Integral` representing whether the given objects are unequal.
     *
     *
     * @warning
     * Using this method with several arguments can be confusing. It does not
     * return whether `T1`, `T2`, ...`Tn` are all unequal, but whether `T1`
     * is different from `T2`, `T2` different from `T3`, and so on.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct not_equal;

    template <typename T1, typename T2, typename ...Tn>
    using not_equal_t = typename not_equal<T1, T2, Tn...>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COMPARABLE_HPP
