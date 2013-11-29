/*!
 * @file
 * Defines `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_APPLY_HPP
#define BOOST_MPL11_APPLY_HPP

#include <boost/mpl11/fwd/apply.hpp>

#include <boost/mpl11/detail/no_decay.hpp>


namespace boost { namespace mpl11 {
    namespace apply_detail {
        template <typename F>
        auto pick() -> typename F::apply;

        template <typename F, typename ...Args>
        auto pick(detail::no_decay<Args>*...) ->
            typename F::template apply<Args...>;
    } // end namespace apply_detail

    template <typename F, typename ...Args>
    struct apply
        : decltype(apply_detail::pick<F>((detail::no_decay<Args>*)nullptr...))
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_APPLY_HPP
