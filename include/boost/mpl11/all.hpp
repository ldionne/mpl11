/*!
 * @file
 * Defines `boost::mpl11::all`.
 */

#ifndef BOOST_MPL11_ALL_HPP
#define BOOST_MPL11_ALL_HPP

#include <boost/mpl11/fwd/all.hpp>

#include <boost/mpl11/drop_while.hpp>


namespace boost { namespace mpl11 {
    template <typename Predicate, typename Sequence>
    struct all
        : is_empty<drop_while_t<Predicate, Sequence>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALL_HPP
