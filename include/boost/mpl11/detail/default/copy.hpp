/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::copy`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_COPY_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_COPY_HPP

#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/foldr.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/push_front.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace copy_detail {
    template <typename From, typename To>
    auto copy_impl(category::back_extensible_sequence*, int)
        -> algorithm::foldl<From, To, quote<push_back>>
    ;

    template <typename From, typename To>
    auto copy_impl(category::extensible_associative_sequence*, int)
        -> algorithm::foldl<From, To, quote<insert>>
    ;

    template <typename From, typename To>
    auto copy_impl(category::front_extensible_sequence*, ...)
        -> algorithm::foldr<From, To, quote<push_front>>
    ;
} // end namespace copy_detail

template <typename From, typename To, typename Insert>
struct dispatch<detail::default_<tag::copy>, From, To, Insert>
    : algorithm::foldl<From, To, Insert>
{ };

template <typename From, typename To>
struct dispatch<detail::default_<tag::copy>, From, To>
    : decltype(
        copy_detail::copy_impl<From, To>(
            (typename category_of<To>::type*)nullptr, int()
        )
    )
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_COPY_HPP
