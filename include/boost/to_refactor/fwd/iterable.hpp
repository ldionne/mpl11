/*!
 * @file
 * Forward declares the @ref Iterable module.
 */

#ifndef BOOST_MPL11_FWD_ITERABLE_HPP
#define BOOST_MPL11_FWD_ITERABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/foldable.hpp>
#include <boost/mpl11/fwd/functor.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>
#include <boost/mpl11/fwd/orderable.hpp>

// For drop_until and take_until
#include <boost/mpl11/fwd/compose.hpp>
#include <boost/mpl11/fwd/not.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    namespace rules {
        template <typename, typename, typename = true_>
        struct unpack_impl;
    } // end namespace rules

    /*!
     * Invokes a metafunction class with the contents of a finite iterable.
     *
     * Specifically, `unpack<Iter, F>` is a nullary metafunction equivalent
     * to `apply<F, a0, ..., an>`, where `a0`, ...,`an` are the elements
     * in the iterable.
     */
    template <typename Iter, typename F>
    BOOST_MPL11_DOXYGEN_ALIAS(unpack, rules::unpack_impl<Iter, F>);


    /*!
     * Default instantiation of the `Functor` typeclass for iterables.
     *
     * ### `fmap<F, Iter>`
     * Returns the result of applying `F` to each element of the iterable.
     */
    template <>
    struct Functor<iterable_tag> BOOST_MPL11_IF_DOXYGEN({ });
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERABLE_HPP
