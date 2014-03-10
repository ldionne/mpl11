/*!
 * @file
 * Forward declares the @ref Maybe datatype.
 */

#ifndef BOOST_MPL11_FWD_MAYBE_HPP
#define BOOST_MPL11_FWD_MAYBE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @defgroup Maybe Maybe
     *
     * `Maybe` encapsulates an optional value.
     *
     * A `Maybe` either contains a value (represented as `just<x>`), or it is
     * empty (represented as `nothing`).
     *
     *
     * ### Instance of
     * `Functor`
     *
     * @todo
     * - Instantiate `Comparable` and `Orderable` for `Maybe`. This might
     *   require `Maybe` to become a parametric datatype. Can we handle this?
     * - Provide more metafunctions like `from_maybe`, `from_just`, etc...
     *
     * @{
     */
    struct Maybe;

    //! Creates an optional value containing `x`.
    template <typename x>
    struct just;

    //! Creates an empty optional value.
    struct nothing BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Applies a metafunction class to a `Maybe`, with a fallback result.
     *
     * Specifically, `maybe` takes a default value `def`, a metafunction
     * class `f` and a `Maybe` `m`. If `m` is `nothing`, `def` is returned.
     * Otherwise, the result of applying `f` to the contents of `m` is
     * returned.
     */
    template <typename def, typename f, typename m>
    struct maybe;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_MAYBE_HPP
