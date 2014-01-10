/*!
 * @file
 * Forward declares the @ref Enumerable typeclass.
 */

#ifndef BOOST_MPL11_FWD_ENUMERABLE_HPP
#define BOOST_MPL11_FWD_ENUMERABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    template <typename> struct succ_impl;
    template <typename> struct pred_impl;

    /*!
     * @ingroup typeclasses
     * @defgroup Enumerable Enumerable
     *
     * The `Enumerable` typeclass defines operations on sequentially
     * ordered datatypes.
     *
     *
     * ### Methods
     * `succ` and `pred`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename Tag>
    struct Enumerable;

    //! Returns the successor of the given object.
    template <typename E>
    BOOST_MPL11_DOXYGEN_ALIAS(succ, succ_impl<E>);

    template <typename E>
    using succ_t = typename succ<E>::type;


    //! Returns the predecessor of the given object.
    template <typename E>
    BOOST_MPL11_DOXYGEN_ALIAS(pred, pred_impl<E>);

    template <typename E>
    using pred_t = typename pred<E>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ENUMERABLE_HPP
