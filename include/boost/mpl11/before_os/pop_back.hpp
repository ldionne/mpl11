/*!
 * @file
 * Defines `boost::mpl11::pop_back`.
 */

#ifndef BOOST_MPL11_POP_BACK_HPP
#define BOOST_MPL11_POP_BACK_HPP

#include <boost/mpl11/fwd/pop_back.hpp>

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/erase.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/prior.hpp>


namespace boost { namespace mpl11 {
    namespace pop_back_detail {
        template <typename Sequence>
        struct assert_nonempty {
            static_assert(!is_empty<Sequence>::type::value,
            "Attempt to use `pop_back` on an empty sequence.");
        };
    } // end namespace pop_back_detail

    template <typename Sequence>
    struct dispatch<tag::pop_back, Sequence>
        : pop_back_detail::assert_nonempty<Sequence>,
          erase<
            Sequence,
            typename prior<
                typename end<Sequence>::type
            >::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_POP_BACK_HPP
