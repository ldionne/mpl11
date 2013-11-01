/*!
 * @file
 * Defines `boost::mpl11::pop_front`.
 */

#ifndef BOOST_MPL11_POP_FRONT_HPP
#define BOOST_MPL11_POP_FRONT_HPP

#include <boost/mpl11/fwd/pop_front.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Seq>
    struct pop_front
        : class_of<Seq>::type::template pop_front_impl<Seq>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_POP_FRONT_HPP
