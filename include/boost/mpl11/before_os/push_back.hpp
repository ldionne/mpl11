/*!
 * @file
 * Defines `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_PUSH_BACK_HPP
#define BOOST_MPL11_PUSH_BACK_HPP

#include <boost/mpl11/fwd/push_back.hpp>

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/single_view.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::push_back, Sequence, Element>
        : identity<
            joined_view<Sequence, single_view<Element>>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PUSH_BACK_HPP
