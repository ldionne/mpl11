/*!
 * @file
 * Forward declares `boost::mpl11::Functor`.
 */

#ifndef BOOST_MPL11_FWD_FUNCTOR_HPP
#define BOOST_MPL11_FWD_FUNCTOR_HPP

namespace boost { namespace mpl11 {
    template <typename, typename> struct map_impl;

    /*!
     * @ingroup typeclasses
     * @defgroup Functor Functor
     *
     * The `Functor` typeclass is used for types that can be mapped over.
     *
     * Instances of `Functor` must satisfy the following laws:
     *
            map id == id
            map (f . g) == map f . map g
     *
     *
     * ### Methods
     * `map`
     *
     * @{
     */
    template <typename Tag>
    struct Functor;

    template <typename Function, typename Functor>
    using map = map_impl<Function, Functor>;

    template <typename Function, typename Functor>
    using map_t = typename map<Function, Functor>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FUNCTOR_HPP
