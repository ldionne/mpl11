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
     * Applies the contents of a sequence to a `MetafunctionClass`.
     *
     * The default implementation copies each element of `%Sequence`
     * one by one into `mpl11::apply<F>`. This has linear time complexity.
     *
     * Sequences whose implementation allow it should specialize this
     * metafunction to give it a more efficient implementation.
     */
    template <typename Sequence, typename F>
    struct unpack;

    template <typename Sequence, typename F>
    using unpack_t = typename unpack<Sequence, F>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_UNPACK_HPP
