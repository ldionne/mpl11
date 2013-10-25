/*!
 * @file
 * Defines `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_IS_EMPTY_HPP
#define BOOST_MPL11_IS_EMPTY_HPP

#include <boost/mpl11/fwd/is_empty.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct is_empty
        : class_<Sequence>::type::template is_empty<Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IS_EMPTY_HPP
