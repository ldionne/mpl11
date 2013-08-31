/*!
 * @file
 * Defines `boost::mpl11::detail::tagged_with`.
 */

#ifndef BOOST_MPL11_DETAIL_TAGGED_WITH_HPP
#define BOOST_MPL11_DETAIL_TAGGED_WITH_HPP

#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
namespace detail {
    template <typename Tag, typename T>
    struct tagged_with
        : T
    { };
} // end namespace detail

template <typename Tag, typename T>
struct tag_of<detail::tagged_with<Tag, T>>
    : identity<Tag>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_TAGGED_WITH_HPP
