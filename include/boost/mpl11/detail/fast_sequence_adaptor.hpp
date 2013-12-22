/*!
 * @file
 * Defines `boost::mpl11::detail::fast_sequence_adaptor`.
 */

#ifndef BOOST_MPL11_DETAIL_FAST_SEQUENCE_ADAPTOR_HPP
#define BOOST_MPL11_DETAIL_FAST_SEQUENCE_ADAPTOR_HPP

#include <boost/mpl11/detail/fast_sequence_adaptor_fwd.hpp>

#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/length.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Tag>
    struct begin<detail::fast_sequence_adaptor<Sequence, Tag>>
        : begin<Sequence>
    { };

    template <typename Sequence, typename Tag>
    struct end<detail::fast_sequence_adaptor<Sequence, Tag>>
        : end<Sequence>
    { };

    template <typename Sequence, typename Tag>
    struct length<detail::fast_sequence_adaptor<Sequence, Tag>>
        : length<Sequence>
    { };

    template <typename Sequence, typename Tag>
    struct is_empty<detail::fast_sequence_adaptor<Sequence, Tag>>
        : is_empty<Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_FAST_SEQUENCE_ADAPTOR_HPP
