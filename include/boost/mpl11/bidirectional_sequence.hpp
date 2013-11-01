/*!
 * @file
 * Defines `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/bidirectional_sequence.hpp>

#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/directional_sequence.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/prev.hpp>


namespace boost { namespace mpl11 {
    struct BidirectionalSequence : DirectionalSequence {
        /*!
         * Returns
         * `mpl11::deref<mpl11::prev<mpl11::end<Seq>::type>::type>::type`
         * if `is_empty<Seq>::value` is `false`, and triggers a static
         * assertion otherwise.
         */
        template <typename Seq>
        struct back_impl {
            static_assert(!is_empty<Seq>::type::value,
            "Attempt to use `back` on an empty sequence.");

            using type = typename deref<
                typename prev<typename end<Seq>::type>::type
            >::type;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
