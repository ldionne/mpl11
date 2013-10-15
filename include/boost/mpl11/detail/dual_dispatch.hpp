/*!
 * @file
 * Defines `boost::mpl11::detail::dual_dispatch`.
 */

#ifndef BOOST_MPL11_DETAIL_DUAL_DISPATCH_HPP
#define BOOST_MPL11_DETAIL_DUAL_DISPATCH_HPP

#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Operation, typename T1, typename T2>
    using dual_dispatch = dispatch<
        tag::dual<Operation>,
        typename category_of<T1>::type,
        typename category_of<T2>::type
    >;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_DUAL_DISPATCH_HPP
