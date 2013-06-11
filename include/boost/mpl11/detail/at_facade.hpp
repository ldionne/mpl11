/*!
 * @file
 * This file defines the implementation of `boost::mpl11::at` for facades.
 */

#ifndef BOOST_MPL11_DETAIL_AT_FACADE_HPP
#define BOOST_MPL11_DETAIL_AT_FACADE_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace at_facade_detail { struct none; }

namespace extension {
template <typename Impl>
struct at_impl<facade_tag<Impl>> {
    template <typename AssociativeSequence,
              typename Key,
              typename Default = at_facade_detail::none>
    struct apply {
        using type = typename AssociativeSequence::template at<Key, Default>;
    };

    template <typename Sequence, typename N>
    struct apply<Sequence, N, at_facade_detail::none> {
        using type = typename Sequence::template at<N>;
    };
};
}
}}}

#endif // !BOOST_MPL11_DETAIL_AT_FACADE_HPP
