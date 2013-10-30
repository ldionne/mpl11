/*!
 * @file
 * Defines `boost::mpl11::begin`.
 */

#ifndef BOOST_MPL11_BEGIN_HPP
#define BOOST_MPL11_BEGIN_HPP

#include <boost/mpl11/fwd/begin.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Seq>
    struct begin
        : class_of<Seq>::type::template begin_impl<Seq>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BEGIN_HPP
