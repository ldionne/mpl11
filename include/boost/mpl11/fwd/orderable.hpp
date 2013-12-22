/*!
 * @file
 * Forward declares `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_FWD_ORDERABLE_HPP
#define BOOST_MPL11_FWD_ORDERABLE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * Type implementing the `<`, `<=`, `>` and `>=` C++ operators.
     *
     *
     * ## Notation
     * | Expression      | Description
     * | ----------      | -----------
     * | `A0`, ..., `An` | Compatible `Orderable`s
     *
     *
     * ## Valid expressions
     * | Expression                   | Type
     * | ----------                   | ----
     * | `less<A0, ..., An>`          | Boolean `Integral`
     * | `less_equal<A0, ..., An>`    | Boolean `Integral`
     * | `greater<A0, ..., An>`       | Boolean `Integral`
     * | `greater_equal<A0, ..., An>` | Boolean `Integral`
     */
    struct Orderable {

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename X, typename Y>
        struct less_impl;
#endif

        //! Equivalent to `not_<less<Y, X>>`.
        template <typename X, typename Y>
        struct less_equal_impl;

        //! Equivalent to `less<Y, X>`.
        template <typename X, typename Y>
        struct greater_impl;

        //! Equivalent to `not_<less<X, Y>>`.
        template <typename X, typename Y>
        struct greater_equal_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ORDERABLE_HPP
