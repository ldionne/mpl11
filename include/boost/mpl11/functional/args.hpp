/*!
 * @file
 * This file defines `boost::mpl11::args`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_ARGS_HPP
#define BOOST_MPL11_FUNCTIONAL_ARGS_HPP

#include <boost/mpl11/int.hpp>
#include <boost/mpl11/view/sliced_view.hpp>

#include <boost/integer_traits.hpp>


namespace boost { namespace mpl11 {
    template <int First = 0, int Last = integer_traits<int>::const_max>
    struct args {
        static_assert(First <= Last,
            "bad indexing of the `args<>` placeholder");

        struct mpl11 { struct is_placeholder; };

        template <typename Args, typename Kwargs>
        struct apply {
            using type = sliced_view<Args, int_<First>, int_<Last>>;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_ARGS_HPP
