/*!
 * @file
 * Forward declares `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_FWD_OR_HPP
#define BOOST_MPL11_FWD_OR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup Boolean
     *
     * Returns the result of short-circuit _logical or_ (`||`)
     * on its arguments.
     */
    template <typename A, typename B, typename ...C>
    struct or_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_OR_HPP
