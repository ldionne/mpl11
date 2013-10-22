/*!
 * @file
 * Defines `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP
#define BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/is_empty_fwd.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<tag::default_<tag::is_empty>, Sequence>
        : equal_to<
            typename begin<Sequence>::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP
