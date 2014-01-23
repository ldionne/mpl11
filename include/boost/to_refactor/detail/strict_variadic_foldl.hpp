/*!
 * @file
 * Defines `boost::mpl11::detail::strict_variadic_foldl`.
 */

#ifndef BOOST_MPL11_DETAIL_STRICT_VARIADIC_FOLDL_HPP
#define BOOST_MPL11_DETAIL_STRICT_VARIADIC_FOLDL_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Strict left-fold algorithm processing a variadic parameter pack.
     *
     *
     * @todo
     * Optimize this and make it able to process _huge_ sequences.
     */
    template <typename F, typename State, typename ...T>
    struct strict_variadic_foldl;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/apply.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename F, typename State, typename Head, typename ...Tail>
    struct strict_variadic_foldl<F, State, Head, Tail...> {
    private:
        static constexpr auto instantiate = sizeof(apply<F, State, Head>);

    public:
        using type = typename strict_variadic_foldl<
            F, apply<F, State, Head>, Tail...
        >::type;
    };

    template <typename F, typename State>
    struct strict_variadic_foldl<F, State>
        : State
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STRICT_VARIADIC_FOLDL_HPP
