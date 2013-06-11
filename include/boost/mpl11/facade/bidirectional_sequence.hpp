/*!
 * @file
 * This file defines `boost::mpl11::bidirectional_sequence_facade`.
 */

#ifndef BOOST_MPL11_FACADE_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_FACADE_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/facade/forward_sequence.hpp>
#include <boost/mpl11/intrinsic.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Impl>
struct bidirectional_sequence_facade : forward_sequence_facade<Impl> {

};

namespace extension {
    template <typename Impl>
    struct back_impl<facade_tag<Impl>> {
        template <typename Sequence>
        struct apply { using type = typename Sequence::back; };
    };
}
}}}

#endif // !BOOST_MPL11_FACADE_BIDIRECTIONAL_SEQUENCE_HPP
