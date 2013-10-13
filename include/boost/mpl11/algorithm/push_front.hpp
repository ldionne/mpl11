/*!
 * @file
 * Defines `boost::mpl11::push_front`.
 */

#ifndef BOOST_MPL11_ALGORITHM_PUSH_FRONT_HPP
#define BOOST_MPL11_ALGORITHM_PUSH_FRONT_HPP

#include <boost/mpl11/algorithm/push_front_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/view/joined.hpp>
#include <boost/mpl11/view/single_element.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::push_front>, Sequence, Element>
        : identity<
            view::joined<view::single_element<Element>, Sequence>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_PUSH_FRONT_HPP
