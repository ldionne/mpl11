/*!
 * @file
 * This file defines `boost::mpl11::at` for facades.
 */

#ifndef BOOST_MPL11_FACADE_AT_HPP
#define BOOST_MPL11_FACADE_AT_HPP

#include <boost/mpl11/detail/none.hpp>
#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/at.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, at>::type>
    struct at_impl<facade_tag<T>> {
        template <typename AssociativeSequence, typename Key,
                  typename Default = detail::none>
        struct apply
            : AssociativeSequence::template at<Key, Default>
        { };

        template <typename Sequence, typename N>
        struct apply<Sequence, N, detail::none>
            : Sequence::template at<N>
        { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_AT_HPP
