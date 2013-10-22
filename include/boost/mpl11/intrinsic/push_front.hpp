/*!
 * @file
 * Defines `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/push_front_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::push_front>, Sequence, Element>
        : insert<
            Sequence, typename begin<Sequence>::type, Element
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
