/*!
 * @file
 * Defines `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_PUSH_FRONT_HPP
#define BOOST_MPL11_PUSH_FRONT_HPP

#include <boost/mpl11/fwd/push_front.hpp>

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/single_view.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::push_front, Sequence, Element>
        : identity<
            joined_view<single_view<Element>, Sequence>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PUSH_FRONT_HPP
