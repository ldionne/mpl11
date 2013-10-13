/*!
 * @file
 * Defines `boost::mpl11::pop_front`.
 */

#ifndef BOOST_MPL11_ALGORITHM_POP_FRONT_HPP
#define BOOST_MPL11_ALGORITHM_POP_FRONT_HPP

#include <boost/mpl11/algorithm/erase.hpp>
#include <boost/mpl11/algorithm/is_empty.hpp>
#include <boost/mpl11/algorithm/pop_front_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>


namespace boost { namespace mpl11 {
    namespace pop_front_detail {
        template <typename Sequence>
        struct assert_nonempty {
            static_assert(!is_empty<Sequence>::type::value,
            "Attempt to use `pop_front` on an empty sequence.");
        };
    } // end namespace pop_front_detail

    template <typename Sequence>
    struct dispatch<tag::default_<tag::pop_front>, Sequence>
        : pop_front_detail::assert_nonempty<Sequence>,
          erase<
            Sequence,
            typename begin<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_POP_FRONT_HPP
