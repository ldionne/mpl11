/*!
 * @file
 * Forward declares `boost::mpl11::value_of`.
 */

#ifndef BOOST_MPL11_FWD_VALUE_OF_HPP
#define BOOST_MPL11_FWD_VALUE_OF_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the value that _would_ be used for an element
     * in an `AssociativeSequence`.
     */
    template <typename Sequence, typename Element>
    struct value_of;

    template <typename Sequence, typename Element>
    using value_of_t = typename value_of<Sequence, Element>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_VALUE_OF_HPP
