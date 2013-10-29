/*!
 * @file
 * Defines `boost::mpl11::apply_wrap`.
 */

#ifndef BOOST_MPL11_APPLY_WRAP_HPP
#define BOOST_MPL11_APPLY_WRAP_HPP

#include <boost/mpl11/fwd/apply_wrap.hpp>


namespace boost { namespace mpl11 {
    namespace apply_wrap_detail {
        template <typename F>
        auto pick() -> typename F::apply;

        template <typename F>
        auto pick() -> typename F::template apply<>;
    } // end namespace apply_wrap_detail

    template <typename F, typename ...Args>
    struct apply_wrap
        : F::template apply<Args...>
    { };

    template <typename F>
    struct apply_wrap<F>
        : decltype(apply_wrap_detail::pick<F>())
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_APPLY_WRAP_HPP
