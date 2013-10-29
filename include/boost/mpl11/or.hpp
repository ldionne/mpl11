/*!
 * @file
 * Defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OR_HPP
#define BOOST_MPL11_OR_HPP

#include <boost/mpl11/fwd/or.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : or_<F1, or_<F2, Fn...>>
    { };

    template <typename F1, typename F2>
    struct or_<F1, F2>
        : class_of<typename F1::type>::type::template or_impl<F1, F2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OR_HPP
