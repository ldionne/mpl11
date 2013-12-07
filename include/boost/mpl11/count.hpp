/*!
 * @file
 * Defines `boost::mpl11::count`.
 */

#ifndef BOOST_MPL11_COUNT_HPP
#define BOOST_MPL11_COUNT_HPP

#include <boost/mpl11/fwd/count.hpp>

#include <boost/mpl11/count_if.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct count
        : count_if<Sequence, partial<quote<equal>, Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUNT_HPP
