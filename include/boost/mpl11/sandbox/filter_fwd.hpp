/*!
 * @file
 * Forward declares `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_FWD_FILTER_HPP
#define BOOST_MPL11_FWD_FILTER_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the elements of a `%Sequence` satisfying
     * `Predicate`.
     *
     * Additionally, `mpl11::filter` is an algorithm returning a new
     * `Container` containing the elements of `%Sequence` satisfying
     * `Predicate`. To use `mpl11::filter` as an algorithm, `%Sequence`
     * must be a `Container`.
     */
    template <typename Sequence, typename Predicate>
    struct filter;

    template <typename Sequence, typename Predicate>
    using filter_t = typename filter<Sequence, Predicate>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FILTER_HPP
