/*!
 * @file
 * This file defines `boost::mpl11::detail::parse_args`.
 */

#ifndef BOOST_MPL11_DETAIL_PARSE_ARGS_HPP
#define BOOST_MPL11_DETAIL_PARSE_ARGS_HPP

#include <boost/mpl11/container_fwd.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic_fwd.hpp>
#include <boost/mpl11/trait/is_named_argument.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
namespace parse_args_detail {
    template <int N = 0, typename Args = vector<>, typename Kwargs = map<>>
    struct parse_info {
        template <typename Argument>
        struct add_arg {
            static_assert(empty<Kwargs>::value,
                "found a positional argument after a named argument");

            using type = parse_info<
                N + 1, typename push_back<Args, Argument>::type, Kwargs
            >;
        };

        template <typename Argument>
        class add_kwarg {
            using NamedArgPair = pair<
                typename Argument::key,
                typename Argument::value
            >;

        public:
            using type = parse_info<
                N + 1, Args, typename insert<Kwargs, NamedArgPair>::type
            >;
        };

        using args = Args;
        using kwargs = Kwargs;
    };

    template <typename ParseInfo, typename ...Args>
    struct parse_args_impl {
        using type = ParseInfo;
    };

    template <typename ParseInfo, typename A0, typename ...An>
    struct parse_args_impl<ParseInfo, A0, An...>
        : parse_args_impl<
            typename if_<trait::is_named_argument<A0>,
                eval<typename ParseInfo::template add_kwarg<A0>>,
                eval<typename ParseInfo::template add_arg<A0>>
            >::type,
            An...
        >
    { };
} // end namespace parse_args_detail

template <typename ...Args>
struct parse_args
    : parse_args_detail::parse_args_impl<
        parse_args_detail::parse_info<>, Args...
    >
{ };
}}}}

#endif // !BOOST_MPL11_DETAIL_PARSE_ARGS_HPP

#include <boost/mpl11/container/map.hpp>
#include <boost/mpl11/container/pair.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/intrinsic/empty.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
