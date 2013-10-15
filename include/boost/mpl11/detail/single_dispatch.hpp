/*!
 * @file
 * Defines `boost::mpl11::detail::single_dispatch`.
 */

#ifndef BOOST_MPL11_DETAIL_SINGLE_DISPATCH_HPP
#define BOOST_MPL11_DETAIL_SINGLE_DISPATCH_HPP

#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Operation, typename T>
    using single_dispatch = dispatch<
        tag::single<Operation>,
        typename category_of<T>::type
    >;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_SINGLE_DISPATCH_HPP
