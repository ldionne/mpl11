/*!
 * @file
 * This file defines `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_OR_HPP
#define BOOST_MPL11_OR_HPP

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename F1, typename F2, typename ...Fn>
    struct or_
        : not_<
            and_<
                not_<F1>, not_<F2>, not_<Fn>...
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OR_HPP
