/*!
 * @file
 * Defines `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_PUSH_BACK_HPP
#define BOOST_MPL11_PUSH_BACK_HPP

#include <boost/mpl11/fwd/push_back.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Element>
    struct push_back
        : class_of<Container>::type::template
            push_back_impl<Container, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PUSH_BACK_HPP
