/*!
 * @file
 * Defines `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/push_back_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::push_back>, Sequence, Element>
        : insert<
            Sequence, typename end<Sequence>::type, Element
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
