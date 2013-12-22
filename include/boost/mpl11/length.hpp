/*!
 * @file
 * Defines `boost::mpl11::length`.
 */

#ifndef BOOST_MPL11_LENGTH_HPP
#define BOOST_MPL11_LENGTH_HPP

#include <boost/mpl11/fwd/length.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct length
        : class_of<Sequence>::type::template length_impl<Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LENGTH_HPP
