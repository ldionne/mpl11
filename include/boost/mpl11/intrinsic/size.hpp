/*!
 * @file
 * Defines `boost::mpl11::size`.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_HPP

#include <boost/mpl11/algorithm/distance.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/size_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<tag::default_<tag::size>, Sequence>
        : algorithm::distance<
            typename begin<Sequence>::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_SIZE_HPP
