/*!
 * @file
 * This file defines the `boost::mpl11::deref` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_DEREF_HPP
#define BOOST_MPL11_INTRINSIC_DEREF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct deref : detail::tag_dispatched<deref> {

        };
    }

    template <typename Iterator, typename ...Args>
    struct deref
        : apply_raw<intrinsic::deref, Iterator, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_DEREF_HPP
