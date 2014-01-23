/*!
 * @file
 * Forward declares the @ref Functor typeclass.
 */

#ifndef BOOST_MPL11_FWD_FUNCTOR_HPP
#define BOOST_MPL11_FWD_FUNCTOR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Functor Functor
     *
     * The `Functor` typeclass is used for types that can be mapped over.
     *
     * Instances of `Functor` must satisfy the following laws:
     *
        @code
            fmap id == id
            fmap (f . g) == fmap f . fmap g
        @endcode
     *
     *
     * ### Methods
     * `fmap`
     *
     * @{
     */
    template <typename Datatype>
    struct Functor;

    //! Returns the result of mapping a metafunction class over a `Functor`.
    template <typename f, typename structure>
    struct fmap;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FUNCTOR_HPP
