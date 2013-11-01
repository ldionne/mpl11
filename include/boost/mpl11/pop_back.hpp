/*!
 * @file
 * Defines `boost::mpl11::pop_back`.
 */

#ifndef BOOST_MPL11_POP_BACK_HPP
#define BOOST_MPL11_POP_BACK_HPP

#include <boost/mpl11/fwd/pop_back.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Seq>
    struct pop_back
        : class_of<Seq>::type::template pop_back_impl<Seq>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_POP_BACK_HPP
