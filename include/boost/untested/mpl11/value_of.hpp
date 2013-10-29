/*!
 * @file
 * Defines `boost::mpl11::value_of`.
 */

#ifndef BOOST_MPL11_VALUE_OF_HPP
#define BOOST_MPL11_VALUE_OF_HPP

#include <boost/mpl11/fwd/value_of.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct value_of
        : class_<Sequence>::type::template value_of<Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VALUE_OF_HPP
