/*!
 * @file
 * Defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_AND_HPP
#define BOOST_MPL11_AND_HPP

#include <boost/mpl11/fwd/and.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct and_
        : and_<F1, and_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct and_<F1, F2>
        : class_of<typename F1::type>::type::template and_impl<F1, F2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AND_HPP
