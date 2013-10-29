/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_INSERT_HPP
#define BOOST_MPL11_INSERT_HPP

#include <boost/mpl11/fwd/insert.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename ...Args>
    struct insert
        : class_<Sequence>::type::template insert<Sequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_HPP
