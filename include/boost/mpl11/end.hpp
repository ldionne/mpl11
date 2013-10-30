/*!
 * @file
 * Defines `boost::mpl11::end`.
 */

#ifndef BOOST_MPL11_END_HPP
#define BOOST_MPL11_END_HPP

#include <boost/mpl11/fwd/end.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Seq>
    struct end
        : class_of<Seq>::type::template end_impl<Seq>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_END_HPP
