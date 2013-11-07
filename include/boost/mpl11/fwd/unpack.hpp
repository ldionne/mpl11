/*!
 * @file
 * Forward declares `boost::mpl11::unpack`.
 */

#ifndef BOOST_MPL11_FWD_UNPACK_HPP
#define BOOST_MPL11_FWD_UNPACK_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Applies the contents of a sequence to a @ref MetafunctionClass.
     *
     *
     * @todo
     * Document the default behavior + semantics.
     *
     * @todo
     * Document the fact that this should be specialized
     * for variadic sequences.
     *
     * @todo
     * Consider making this an intrinsic or an algorithm.
     *
     * @todo
     * Use a minimal sequence in the unit tests instead of vector, which
     * could specialize unpack.
     */
    template <typename Sequence, typename F>
    struct unpack;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_UNPACK_HPP
