/*!
 * @file
 * This file defines `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_APPLY_HPP
#define BOOST_MPL11_APPLY_HPP

#include <boost/mpl11/apply_raw.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
    template <typename Expression>
    struct lambda;

    template <typename M, typename ...Args>
    struct apply
        : apply_raw<typename lambda<M>::type, Args...>
    { };
}}}

#endif // !BOOST_MPL11_APPLY_HPP

#include <boost/mpl11/lambda.hpp>
