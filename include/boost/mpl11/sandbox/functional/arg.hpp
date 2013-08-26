/*!
 * @file
 * This file defines `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_ARG_HPP
#define BOOST_MPL11_FUNCTIONAL_ARG_HPP

#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/view/single_view.hpp>


namespace boost { namespace mpl11 {
    template <int N>
    struct arg {
        struct mpl11 { struct is_placeholder; };

        template <typename Args, typename Kwargs>
        struct apply {
            using type = single_view<typename at_c<Args, N - 1>::type>;
        };
    };

    using _1 = arg<1>;
    using _2 = arg<2>;
    using _3 = arg<3>;
    using _4 = arg<4>;
    using _5 = arg<5>;
    using _6 = arg<6>;
    using _7 = arg<7>;
    using _8 = arg<8>;
    using _9 = arg<9>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_ARG_HPP
