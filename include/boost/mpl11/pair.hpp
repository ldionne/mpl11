/*!
 * @file
 * Defines `boost::mpl11::pair`.
 */

#ifndef BOOST_MPL11_PAIR_HPP
#define BOOST_MPL11_PAIR_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Second>
    struct pair;

    namespace tag { struct first; struct second; }

    template <typename First, typename Second>
    struct dispatch<tag::first, pair<First, Second>>
        : always<First>
    { };

    template <typename First, typename Second>
    struct dispatch<tag::second, pair<First, Second>>
        : always<Second>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PAIR_HPP
