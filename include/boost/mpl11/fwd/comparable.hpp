/*!
 * @file
 * Forward declares `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_FWD_COMPARABLE_HPP
#define BOOST_MPL11_FWD_COMPARABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2>
    struct equal_impl;

    template <typename T1, typename T2>
    struct not_equal_impl;

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
     * Those methods can be invoked with more than two elements.
     * Specifically, `method<T1, ..., Tn>` is equivalent to
     * `and_<method<T1, T2>, method<T2, ..., Tn>>`, and `method<T1, T2>`
     * uses the usual tag dispatching technique.
     *
     * ### Minimal complete definition
     * Either `equal` or `not_equal`.
     *
     *
     * @note
     * This typeclass is a bit special because all C++ types are implicitly
     * instances of it. For convenience, equality and inequality for
     * arbitrary types is defined in terms of `std::is_same`.
     *
     *
     * @todo
     * Implement multiple arguments for `equal` and `not_equal`,
     * as documented.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Comparable;

    //! Boolean `Integral` representing whether the given objects are equal.
    template <typename T1, typename T2>
    BOOST_MPL11_DOXYGEN_ALIAS(equal, equal_impl<T1, T2>);

    template <typename T1, typename T2>
    using equal_t = typename equal<T1, T2>::type;

    /*!
     * Boolean `Integral` representing whether the given objects are unequal.
     *
     *
     * @warning
     * Using this method with several arguments can be confusing. It does not
     * return whether `T1`, `T2`, ...`Tn` are all unequal, but whether `T1`
     * is different from `T2`, `T2` different from `T3`, and so on.
     */
    template <typename T1, typename T2>
    BOOST_MPL11_DOXYGEN_ALIAS(not_equal, not_equal_impl<T1, T2>);

    template <typename T1, typename T2>
    using not_equal_t = typename not_equal<T1, T2>::type;

    //! @}

    /*!
     * @ingroup tags
     *
     * Tag representing the `Comparable` typeclass.
     */
    struct comparable_tag BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COMPARABLE_HPP
