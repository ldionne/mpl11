/*!
 * @file
 * Forward declares `boost::mpl11::flatten_if`.
 */

#ifndef BOOST_MPL11_FWD_FLATTEN_IF_HPP
#define BOOST_MPL11_FWD_FLATTEN_IF_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` flattening the elements of another `Sequence` satisfying a
     * given `Predicate`.
     *
     * Specifically, the elements of `%Sequence` satisfying `Predicate` are
     * considered as `Sequence`s themselves and their content is unpacked in
     * the resulting sequence. Elements which do not satisfy `Predicate` are
     * kept in the resulting sequence but they are left as-is.
     *
     * Additionally, `flatten_if` is an algorithm returning a new `Container`
     * created with the elements of `flatten_if`. To use `flatten_if` as an
     * algorithm, `%Sequence` must be a `Container`.
     */
    template <typename Sequence, typename Predicate>
    struct flatten_if;

    template <typename Sequence, typename Predicate>
    using flatten_if_t = typename flatten_if<Sequence, Predicate>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FLATTEN_IF_HPP
