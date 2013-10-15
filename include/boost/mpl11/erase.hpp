/*!
 * @file
 * Defines `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_ERASE_HPP
#define BOOST_MPL11_ERASE_HPP

#include <boost/mpl11/fwd/erase.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
namespace erase_detail {
    template <typename Sequence, typename First, typename Last,
              bool = equal_to<Last, typename end<Sequence>::type>::type::value>
    struct erase_impl
        : identity<
            iterator_range<
                typename begin<Sequence>::type, First
            >
        >
    { };

    template <typename Sequence, typename First, typename Last>
    struct erase_impl<Sequence, First, Last, false>
        : identity<
            joined_view<
                iterator_range<
                    typename begin<Sequence>::type, First
                >,
                iterator_range<
                    Last, typename end<Sequence>::type
                >
            >
        >
    { };
} // end namespace erase_detail

template <typename Sequence, typename Position>
struct dispatch<tag::erase, Sequence, Position>
    : erase<
        Sequence, Position, typename next<Position>::type
    >
{ };

template <typename Sequence, typename First, typename Last>
struct dispatch<tag::erase, Sequence, First, Last>
    : erase_detail::erase_impl<Sequence, First, Last>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_HPP
