/*!
 * @file
 * Defines `boost::mpl11::clear`.
 */

#ifndef BOOST_MPL11_INTRINSIC_CLEAR_HPP
#define BOOST_MPL11_INTRINSIC_CLEAR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<tag::default_<tag::clear>, Sequence>
        : erase<
            Sequence,
            typename begin<Sequence>::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_CLEAR_HPP
