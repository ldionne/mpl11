/*!
 * @file
 * Defines `boost::mpl11::ForwardIterable::front`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERABLE_FRONT_HPP
#define BOOST_MPL11_FORWARD_ITERABLE_FRONT_HPP

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/forward_iterable/forward_iterable.hpp>
#include <boost/mpl11/is_empty.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct ForwardIterable::front {
        static_assert(!is_empty<I>::type::value,
        "Attempt to use `front` on an empty sequence.");

        using type = typename deref<typename begin<I>::type>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERABLE_FRONT_HPP
