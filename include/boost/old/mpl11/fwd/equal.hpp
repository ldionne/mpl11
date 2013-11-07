/*!
 * @file
 * Forward declares `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_FWD_EQUAL_HPP
#define BOOST_MPL11_FWD_EQUAL_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns whether two sequences are identical when compared
     * element-by-element with a custom `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * If `size<Sequence1>::type::value == size<Sequence2>::type::value`,
     * equivalent to
       @code
            all_of<
                zip_view<Sequence1, Sequence2>,
                unpack_args<Predicate>
            >
       @endcode
     * Otherwise, it is equivalent to `identity<false_>`.
     */
    template <
        typename Sequence1,
        typename Sequence2,
        typename Predicate = detail::optional
    >
    struct equal BOOST_MPL11_DOXYGEN_ONLY(<Sequence1, Sequence2, Predicate>);

    /*!
     * @ingroup algorithms
     * Returns whether two sequences are identical when compared
     * element-by-element.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `equal<Sequence1, Sequence2, equal_to<_1, _2>>`.
     */
    template <typename Sequence1, typename Sequence2>
    struct equal<Sequence1, Sequence2>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_EQUAL_HPP
