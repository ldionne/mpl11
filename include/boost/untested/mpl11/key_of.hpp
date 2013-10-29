/*!
 * @file
 * Defines `boost::mpl11::key_of`.
 */

#ifndef BOOST_MPL11_KEY_OF_HPP
#define BOOST_MPL11_KEY_OF_HPP

#include <boost/mpl11/fwd/key_of.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct key_of
        : class_<Sequence>::type::template key_of<Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_KEY_OF_HPP
