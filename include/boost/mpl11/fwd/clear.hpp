/*!
 * @file
 * Forward declares `boost::mpl11::clear`.
 */

#ifndef BOOST_MPL11_FWD_CLEAR_HPP
#define BOOST_MPL11_FWD_CLEAR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns an empty sequence concept-identical to `Sequence`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            erase<
                Sequence,
                begin<Sequence>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence>
    struct clear;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CLEAR_HPP
