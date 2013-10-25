/*!
 * @file
 * Defines `boost::mpl11::at`.
 */

#ifndef BOOST_MPL11_AT_HPP
#define BOOST_MPL11_AT_HPP

#include <boost/mpl11/fwd/at.hpp>

#include <boost/mpl11/class.hpp>
#include <boost/mpl11/integral_c.hpp> // for at_c


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key, typename Default>
    struct at
        : class_<Sequence>::type::template at<Sequence, Key, Default>
    { };

    template <typename Sequence, typename KeyOrIndex>
    struct at<Sequence, KeyOrIndex>
        : class_<Sequence>::type::template at<Sequence, KeyOrIndex>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AT_HPP
