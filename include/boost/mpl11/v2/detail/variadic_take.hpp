
/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_take`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_TAKE_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_TAKE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * `MetafunctionClass` invoking another `MetafunctionClass` with the
     * first `N` arguments it is invoked with.
     */
    template <std_size_t N, typename F>
    struct variadic_take;
}}}


namespace boost { namespace mpl11 { namespace detail {
    template <std_size_t N, typename F>
    struct variadic_take {
        template <typename ...Args>
        using apply = ;
        #error implement me
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_TAKE_HPP
