/*!
 * @file
 * Forward declares `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_FWD_AND_HPP
#define BOOST_MPL11_FWD_AND_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup Boolean
     *
     * Returns the result of short-circuit _logical and_ (`&&`)
     * on its arguments.
     */
    template <typename A, typename B, typename ...C>
    struct and_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AND_HPP
