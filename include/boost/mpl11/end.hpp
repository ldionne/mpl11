/*!
 * @file
 * Defines `boost::mpl11::end`.
 */

#ifndef BOOST_MPL11_END_HPP
#define BOOST_MPL11_END_HPP

#include <boost/mpl11/fwd/end.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct end
        : class_of<Sequence>::type::template end_impl<Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_END_HPP
