/*!
 * @file
 * Defines `boost::mpl11::empty_sequence`.
 */

#ifndef BOOST_MPL11_EMPTY_SEQUENCE_HPP
#define BOOST_MPL11_EMPTY_SEQUENCE_HPP

#include <boost/mpl11/fwd/empty_sequence.hpp>

#include <boost/mpl11/list.hpp>


namespace boost { namespace mpl11 {
    struct empty_sequence : list<> { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EMPTY_SEQUENCE_HPP
