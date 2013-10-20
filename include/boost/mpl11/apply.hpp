/*!
 * @file
 * Defines `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_APPLY_HPP
#define BOOST_MPL11_APPLY_HPP

#include <boost/mpl11/fwd/apply.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename MetafunctionClass, typename ...Args>
    struct apply
        : class_<MetafunctionClass>::type::template apply<Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_APPLY_HPP
