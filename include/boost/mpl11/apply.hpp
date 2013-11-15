/*!
 * @file
 * Defines `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_APPLY_HPP
#define BOOST_MPL11_APPLY_HPP

#include <boost/mpl11/fwd/apply.hpp>


namespace boost { namespace mpl11 {
    namespace apply_detail {
        template <typename F>
        auto pick() -> typename F::apply;

        template <typename F>
        auto pick() -> typename F::template apply<>;
    } // end namespace apply_detail

    template <typename F, typename ...Args>
    struct apply
        : F::template apply<Args...>
    { };

    template <typename F>
    struct apply<F>
        : decltype(apply_detail::pick<F>())
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_APPLY_HPP
