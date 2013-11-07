/*!
 * @file
 * Defines `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_PUSH_FRONT_HPP
#define BOOST_MPL11_PUSH_FRONT_HPP

#include <boost/mpl11/fwd/push_front.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Element>
    struct push_front
        : class_of<Container>::type::template
            push_front_impl<Container, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PUSH_FRONT_HPP
