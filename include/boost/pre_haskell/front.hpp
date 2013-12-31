/*!
 * @file
 * Defines `boost::mpl11::front`.
 */

#ifndef BOOST_MPL11_FRONT_HPP
#define BOOST_MPL11_FRONT_HPP

#include <boost/mpl11/fwd/front.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct front
        : class_of<Sequence>::type::template front_impl<Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FRONT_HPP
