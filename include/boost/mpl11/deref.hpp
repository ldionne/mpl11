/*!
 * @file
 * Defines `boost::mpl11::deref`.
 */

#ifndef BOOST_MPL11_DEREF_HPP
#define BOOST_MPL11_DEREF_HPP

#include <boost/mpl11/fwd/deref.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator>
    struct deref
        : class_<Iterator>::type::template deref<Iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DEREF_HPP
