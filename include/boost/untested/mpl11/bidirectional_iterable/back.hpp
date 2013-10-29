/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterable::back`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERABLE_BACK_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERABLE_BACK_HPP

#include <boost/mpl11/bidirectional_iterable/bidirectional_iterable.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/prev.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct BidirectionalIterable::back {
        static_assert(!is_empty<I>::type::value,
        "Attempt to use `back` on an empty iterable.");

        using type = typename deref<
            typename prev<typename end<I>::type>::type
        >::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERABLE_BACK_HPP
