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
            fmap id == id
            fmap (f . g) == fmap f . fmap g
     *
     *
     * ### Methods
     * `fmap`
     *
     * @{
     */
    template <typename Tag>
    struct Functor;

    template <typename Function, typename Functor>
    struct fmap;

    template <typename Function, typename Functor>
    using fmap_t = typename fmap<Function, Functor>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FUNCTOR_HPP
