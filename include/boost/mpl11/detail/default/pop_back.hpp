/*!
 * @file
 * Defines the default implementation of `boost::mpl11::intrinsic::pop_back`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_POP_BACK_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_POP_BACK_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace pop_back_detail {
    template <typename Sequence>
    struct assert_nonempty {
        static_assert(!intrinsic::is_empty<Sequence>::type::value,
        "Attempt to use `pop_back` on an empty sequence.");
    };
} // end namespace pop_back_detail

template <typename Sequence>
struct dispatch<detail::default_<tag::pop_back>, Sequence>
    : pop_back_detail::assert_nonempty<Sequence>,
      intrinsic::erase<
        Sequence,
        typename intrinsic::prior<
            typename intrinsic::end<Sequence>::type
        >::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_POP_BACK_HPP
