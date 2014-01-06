/*!
 * @file
 * Defines `boost::mpl11::none`.
 */

#ifndef BOOST_MPL11_NONE_HPP
#define BOOST_MPL11_NONE_HPP

#include <boost/mpl11/fwd/none.hpp>

#include <boost/mpl11/filter.hpp>


namespace boost { namespace mpl11 {
    template <typename Predicate, typename Sequence>
    struct none
        : is_empty<filter_t<Predicate, Sequence>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NONE_HPP
