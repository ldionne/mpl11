/*!
 * @file
 * Defines `boost::mpl11::size`.
 */

#ifndef BOOST_MPL11_ALGORITHM_SIZE_HPP
#define BOOST_MPL11_ALGORITHM_SIZE_HPP

#include <boost/mpl11/algorithm/distance.hpp>
#include <boost/mpl11/algorithm/size_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<tag::default_<tag::size>, Sequence>
        : distance<
            typename begin<Sequence>::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_SIZE_HPP
