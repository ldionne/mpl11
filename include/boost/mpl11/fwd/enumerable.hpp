/*!
 * @file
 * Forward declares the @ref Enumerable typeclass.
 */

#ifndef BOOST_MPL11_FWD_ENUMERABLE_HPP
#define BOOST_MPL11_FWD_ENUMERABLE_HPP

namespace boost { namespace mpl11 {
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
    template <typename Datatype>
    struct Enumerable;

    //! Returns the successor of the given object.
    template <typename e>
    struct succ;

    //! Returns the predecessor of the given object.
    template <typename e>
    struct pred;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ENUMERABLE_HPP
