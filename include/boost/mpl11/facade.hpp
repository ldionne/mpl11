/*!
 * @file
 * Defines `boost::mpl11::facade`.
 */

#ifndef BOOST_MPL11_FACADE_HPP
#define BOOST_MPL11_FACADE_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    template <typename Self>
    struct facade;

    template <typename OperationTag, typename ...Args>
    struct dispatch<OperationTag, facade<Self>, Args...>
        : apply_wrap<Self, Self, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FACADE_HPP
