/*!
 * @file
 * Forward declares `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_FWD_LAMBDA_HPP
#define BOOST_MPL11_FWD_LAMBDA_HPP

#include <boost/mpl11/fwd/let.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Alias to `mpl1::let<>::in<F>`; provided for convenience.
     */
    template <typename F>
    using lambda = typename let<>::template in<F>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LAMBDA_HPP
