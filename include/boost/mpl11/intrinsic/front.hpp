/*!
 * @file
 * Defines `boost::mpl11::front`.
 */

#ifndef BOOST_MPL11_INTRINSIC_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/front_fwd.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>


namespace boost { namespace mpl11 {
    namespace front_detail {
        template <typename Sequence>
        struct assert_nonempty {
            static_assert(!is_empty<Sequence>::type::value,
            "Attempt to use `front` on an empty sequence.");
        };
    } // end namespace front_detail

    template <typename Sequence>
    struct dispatch<tag::default_<tag::front>, Sequence>
        : front_detail::assert_nonempty<Sequence>,
          deref<typename begin<Sequence>::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_FRONT_HPP
