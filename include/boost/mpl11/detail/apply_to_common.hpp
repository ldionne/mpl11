/*!
 * @file
 * Defines `boost::mpl11::detail::apply_to_common`.
 */

#ifndef BOOST_MPL11_DETAIL_APPLY_TO_COMMON_HPP
#define BOOST_MPL11_DETAIL_APPLY_TO_COMMON_HPP

#include <boost/mpl11/fwd/core.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Cast `x` and `y` to their common datatype, and then apply `method`
     * to the result.
     *
     * `method` must be a call-by-need metafunction.
     */
    template <template <typename ...> class method, typename x, typename y,
        typename Left = typename datatype<typename x::type>::type,
        typename Right = typename datatype<typename y::type>::type,
        typename Common = typename common_datatype<Left, Right>::type
    >
    using apply_to_common = method<
        typename cast_to<Common>::template apply<typename x::type>,
        typename cast_to<Common>::template apply<typename y::type>
    >;
}}}


#include <boost/mpl11/core.hpp>

#endif // !BOOST_MPL11_DETAIL_APPLY_TO_COMMON_HPP
