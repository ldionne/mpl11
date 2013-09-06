/*!
 * @file
 * Defines `boost::mpl11::adaptor`.
 */

#ifndef BOOST_MPL11_ADAPTOR_HPP
#define BOOST_MPL11_ADAPTOR_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/is_inplace_transformation.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 {
template <typename Wrap, typename Object>
struct adaptor BOOST_MPL11_DOXYGEN_ONLY({ });

namespace adaptor_detail {
    template <typename F, typename ...Args>
    struct lazy_apply
        : apply<F, typename Args::type...>
    { };
} // end namespace adaptor_detail

template <typename Operation, typename Wrap, typename Object, typename ...Args>
struct dispatch<Operation, adaptor<Wrap, Object>, Args...>
    : if_<detail::is_inplace_transformation<Operation>,
        adaptor_detail::lazy_apply<Wrap, dispatch<Operation, Object, Args...>>,
        dispatch<Operation, Object, Args...>
    >::type
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ADAPTOR_HPP
