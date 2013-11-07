/*!
 * @file
 * Forward declares `boost::mpl11::contains`.
 */

#ifndef BOOST_MPL11_FWD_CONTAINS_HPP
#define BOOST_MPL11_FWD_CONTAINS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns whether `Sequence` contains one or more elements identical
     * to `Element`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            not_equal_to<
                find<Sequence, Element>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence, typename Element>
    struct contains;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CONTAINS_HPP
