/*!
 * @file
 * Defines `boost::mpl11::detail::eager_any` and
 * `boost::mpl11::detail::eager_any_c`.
 */

#ifndef BOOST_MPL11_DETAIL_EAGER_ANY_HPP
#define BOOST_MPL11_DETAIL_EAGER_ANY_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns whether any of the `Bools` is `true` in a non
     * short-circuiting fashion.
     */
    template <bool ...Bools>
    struct eager_any_c;

    //! @ingroup details
    //! Alias to `eager_any_c<T::value...>`; provided for convenience.
    template <typename ...T>
    using eager_any = eager_any_c<T::value...>;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace eager_any_detail {
        template <typename ...T>
        false_ any_impl(T*...);
        true_ any_impl(...);
    }

    template <bool ...Bools>
    struct eager_any_c
        : decltype(
            eager_any_detail::any_impl(
                typename conditional<Bools, int, int*>::type{}...
            )
        )
    { };

    template <>
    struct eager_any_c<>
        : false_
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_EAGER_ANY_HPP
