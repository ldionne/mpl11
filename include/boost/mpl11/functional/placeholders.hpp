/*!
 * @file
 * This file defines several placeholders for use in placeholder expressions.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_PLACEHOLDERS_HPP
#define BOOST_MPL11_FUNCTIONAL_PLACEHOLDERS_HPP

#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/intrinsic/size.hpp>

#include <boost/integer_traits.hpp>


namespace boost { namespace mpl11 {
template <typename Name>
struct kwarg {
    struct mpl11 { struct is_placeholder; };

    template <typename Args, typename Kwargs>
    struct apply {
        using type = vector<typename at<Kwargs, Name>::type>;
    };
};

template <int N>
struct arg {
    struct mpl11 { struct is_placeholder; };

    template <typename Args, typename Kwargs>
    struct apply {
        using type = vector<typename at_c<Args, N - 1>::type>;
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


namespace args_detail {
    template <typename State, typename Args, int First, int Last>
    struct fold_args
        : if_c<First == Last || size<Args>::value == First,
            State,
            eval<fold_args<
                eval<push_back<State, eval<at_c<Args, First>>>>,
                Args, First + 1, Last
            >>
        >
    { };
} // end namespace args_detail

template <int First = 0, int Last = integer_traits<int>::const_max>
struct args {
    static_assert(First <= Last, "bad indexing of the `args<>` placeholder");
    struct mpl11 { struct is_placeholder; };

    template <typename Args, typename Kwargs>
    struct apply
        : args_detail::fold_args<vector<>, Args, First, Last>
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_PLACEHOLDERS_HPP
