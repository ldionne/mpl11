/*!
 * @file
 * Defines `boost::mpl11::back`.
 */

#ifndef BOOST_MPL11_BACK_HPP
#define BOOST_MPL11_BACK_HPP

#include <boost/mpl11/fwd/back.hpp>

#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/prior.hpp>


namespace boost { namespace mpl11 {
    namespace back_detail {
        template <typename Sequence>
        struct assert_nonempty {
            static_assert(!is_empty<Sequence>::type::value,
            "Attempt to use `back` on an empty sequence.");
        };
    } // end namespace back_detail

    template <typename Sequence>
    struct dispatch<tag::back, Sequence>
        : back_detail::assert_nonempty<Sequence>,
          deref<
            typename prior<
                typename end<Sequence>::type
            >::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_HPP
