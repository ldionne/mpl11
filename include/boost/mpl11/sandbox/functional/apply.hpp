/*!
 * @file
 * This file defines `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_APPLY_HPP
#define BOOST_MPL11_FUNCTIONAL_APPLY_HPP

#include <boost/mpl11/functional_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename M, typename ...Args>
    struct apply
        : apply_raw<typename lambda<M>::type, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_APPLY_HPP

#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/lambda.hpp>
