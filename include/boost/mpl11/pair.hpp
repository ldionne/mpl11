/*!
 * @file
 * Defines `boost::mpl11::pair`.
 */

#ifndef BOOST_MPL11_PAIR_HPP
#define BOOST_MPL11_PAIR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/first_fwd.hpp>
#include <boost/mpl11/intrinsic/second_fwd.hpp>
#include <boost/mpl11/pair_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Second>
    struct dispatch<tag::first, pair<First, Second>>
        : identity<First>
    { };

    template <typename First, typename Second>
    struct dispatch<tag::second, pair<First, Second>>
        : identity<Second>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PAIR_HPP
