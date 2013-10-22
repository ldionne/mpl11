/*!
 * @file
 * Defines `boost::mpl11::pop_back`.
 */

#ifndef BOOST_MPL11_INTRINSIC_POP_BACK_HPP
#define BOOST_MPL11_INTRINSIC_POP_BACK_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/pop_back_fwd.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>


namespace boost { namespace mpl11 {
    namespace pop_back_detail {
        template <typename Sequence>
        struct assert_nonempty {
            static_assert(!is_empty<Sequence>::type::value,
            "Attempt to use `pop_back` on an empty sequence.");
        };
    } // end namespace pop_back_detail

    template <typename Sequence>
    struct dispatch<tag::default_<tag::pop_back>, Sequence>
        : pop_back_detail::assert_nonempty<Sequence>,
          erase<
            Sequence,
            typename prior<
                typename end<Sequence>::type
            >::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_POP_BACK_HPP
