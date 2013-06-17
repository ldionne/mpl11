/*!
 * @file
 * This file defines `boost::mpl11::detail::transfer`.
 */

#ifndef BOOST_MPL11_DETAIL_TRANSFER_HPP
#define BOOST_MPL11_DETAIL_TRANSFER_HPP

namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
template <template <typename ...> class Destination, typename Source>
struct transfer;

template <template <typename ...> class Destination,
          template <typename ...> class Source,
          typename ...Content>
struct transfer<Destination, Source<Content...>> {
    using type = Destination<Content...>;
};
}}}}

#endif // !BOOST_MPL11_DETAIL_TRANSFER_HPP
