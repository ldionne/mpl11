/*!
 * @file
 * This file defines `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_LAMBDA_HPP
#define BOOST_MPL11_FUNCTIONAL_LAMBDA_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional/bind.hpp>
#include <boost/mpl11/functional/protect.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/functional_fwd.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/trait/is_placeholder.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace lambda_detail {
    template <typename T>
    struct get_is_pe { using type = typename T::is_pe; };

    template <typename T>
    struct lambda_impl {
        using is_pe = typename trait::is_placeholder<T>::type;
        using le = T;
    };

    template <template <typename ...> class M, typename ...T>
    struct lambda_impl<M<T...>> {
        // We must make sure there are always at least two arguments to the
        // `or_`, hence the trailing `false_`.
        using is_pe = typename or_<
            trait::is_placeholder<M<T...>>,
            get_is_pe<lambda_impl<T>>...,
            false_
        >::type;

        template <typename ...U>
        struct lazy_protect_bind_helper {
            using type = protect<
                bind<quote<M>, typename lambda_impl<U>::le...>
            >;
        };

        using le =
            typename if_<trait::is_placeholder<M<T...>>,
                M<T...>
            >::template else_if<is_pe,
                eval<lazy_protect_bind_helper<T...>>
            >::template else_<
                M<T...>
            >::type;
    };
} // end namespace lambda_detail

template <typename Expression>
struct lambda {
    using type = typename lambda_detail::lambda_impl<Expression>::le;
};
}}}

#endif // !BOOST_MPL11_FUNCTIONAL_LAMBDA_HPP
