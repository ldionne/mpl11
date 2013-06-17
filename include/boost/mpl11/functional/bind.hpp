/*!
 * @file
 * This file defines `boost::mpl11::bind`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_BIND_HPP
#define BOOST_MPL11_FUNCTIONAL_BIND_HPP

#include <boost/mpl11/algorithm_fwd.hpp>
#include <boost/mpl11/container_fwd.hpp>
#include <boost/mpl11/detail/parse_args.hpp>
#include <boost/mpl11/detail/transfer.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional_fwd.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/empty.hpp>
#include <boost/mpl11/intrinsic/front.hpp>
#include <boost/mpl11/intrinsic/pop_front.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/trait/is_placeholder.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace bind_detail {
template <typename Sequence, typename State, typename BinaryOp>
struct fold_bootstrap
    : if_<empty<Sequence>,
        State,
        eval<fold_bootstrap<
            eval<pop_front<Sequence>>,
            eval<apply<BinaryOp, State, eval<front<Sequence>>>>,
            BinaryOp
        >>
    >
{ };

template <typename Sequence, typename Range>
struct push_back_range
    : if_<empty<Range>,
        Sequence,
        eval<push_back_range<
            eval<push_back<Sequence, eval<front<Range>>>>,
            eval<pop_front<Range>>
        >>
    >
{ };

template <typename Args, typename Kwargs>
struct do_binding;

template <typename Args, typename Kwargs, typename ...T>
struct perform_binding
    : detail::transfer<
        apply_raw,
        typename fold_bootstrap<
            vector<T...>, vector<>, do_binding<Args, Kwargs>
        >::type
    >
{ };

template <typename Args, typename Kwargs>
struct do_binding {
    template <typename Result, typename T>
    struct apply
        : if_<trait::is_placeholder<T>,
            eval<push_back_range<Result, eval<apply_raw<T, Args, Kwargs>>>>,
            eval<push_back<Result, T>>
        >
    { };

    template <typename Result, typename ...T>
    struct apply<Result, bind<T...>>
        : push_back<
            Result,
            typename perform_binding<Args, Kwargs, T...>::type::type
        >
    { };
};

template <typename ...T>
struct bind_impl {
    template <typename ...A>
    class apply {
        using Parsed = typename detail::parse_args<A...>::type;
        using Args = typename Parsed::args;
        using Kwargs = typename Parsed::kwargs;
        using Bound = typename perform_binding<Args, Kwargs, T...>::type;

    public:
        using type = typename Bound::type;
    };
};
} // end namespace bind_detail

template <typename ...T>
struct bind
    : bind_detail::bind_impl<T...>
{ };
}}}

#endif // !BOOST_MPL11_FUNCTIONAL_BIND_HPP

#include <boost/mpl11/algorithm/fold.hpp>
#include <boost/mpl11/container/vector.hpp>
