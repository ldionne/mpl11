/*!
 * @file
 * This file defines `boost::mpl11::forward_sequence_facade`.
 */

#ifndef BOOST_MPL11_FACADE_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_FACADE_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic.hpp>

#include <boost/preprocessor/cat.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Impl>
struct forward_sequence_facade
    : base_facade<Impl>
{ };

#define BOOST_MPL11_DEF_FWD_SEQ_FACADE_INTRINSIC(name)                      \
    template <typename Impl>                                                \
    struct BOOST_PP_CAT(name, _impl)<facade_tag<Impl>> {                    \
        template <typename Sequence>                                        \
        struct apply { using type = typename Sequence::name; };             \
    };                                                                      \
/**/

namespace extension {
    BOOST_MPL11_DEF_FWD_SEQ_FACADE_INTRINSIC(begin)
    BOOST_MPL11_DEF_FWD_SEQ_FACADE_INTRINSIC(end)
    BOOST_MPL11_DEF_FWD_SEQ_FACADE_INTRINSIC(size)
    BOOST_MPL11_DEF_FWD_SEQ_FACADE_INTRINSIC(empty)
    BOOST_MPL11_DEF_FWD_SEQ_FACADE_INTRINSIC(front)
}

#undef BOOST_MPL11_DEF_FWD_SEQ_FACADE_INTRINSIC
}}}

#endif // !BOOST_MPL11_FACADE_FORWARD_SEQUENCE_HPP
