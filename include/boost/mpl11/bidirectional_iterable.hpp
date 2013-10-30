/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterable`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERABLE_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERABLE_HPP

#include <boost/mpl11/fwd/bidirectional_iterable.hpp>

#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/forward_iterable.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/prev.hpp>


namespace boost { namespace mpl11 {
    struct BidirectionalIterable : ForwardIterable {
        /*!
         * Returns `mpl11::deref<mpl11::prev<mpl11::end<I>::type>::type>::type`
         * if `is_empty<I>::value` is `false`, and triggers a static
         * assertion otherwise.
         */
        template <typename I>
        struct back_impl {
            static_assert(!is_empty<I>::type::value,
            "Attempt to use `back` on an empty iterable.");

            using type = typename deref<
                typename prev<typename end<I>::type>::type
            >::type;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERABLE_HPP
