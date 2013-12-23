/*!
 * @file
 * Defines `boost::mpl11::head`.
 */

#ifndef BOOST_MPL11_HEAD_HPP
#define BOOST_MPL11_HEAD_HPP

#include <boost/mpl11/fwd/head.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct head
        : deref<typename begin<S>::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HEAD_HPP
