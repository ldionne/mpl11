/*!
 * @file
 * Defines `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/erase_fwd.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined.hpp>


namespace boost { namespace mpl11 {
namespace erase_detail {
    template <typename Sequence, typename First, typename Last,
              bool = equal_to<
                Last, typename end<Sequence>::type
              >::type::value>
    struct erase_impl
        : algorithm::copy<
            view::bounded_by<
                typename begin<Sequence>::type, First
            >,
            typename clear<Sequence>::type
        >
    { };

    template <typename Sequence, typename First, typename Last>
    struct erase_impl<Sequence, First, Last, false>
        : algorithm::copy<
            view::joined<
                view::bounded_by<
                    typename begin<Sequence>::type, First
                >,
                view::bounded_by<
                    Last, typename end<Sequence>::type
                >
            >,
            typename clear<Sequence>::type
        >
    { };
} // end namespace erase_detail

template <typename Sequence, typename Position>
struct dispatch<tag::default_<tag::erase>, Sequence, Position>
    : erase<
        Sequence, Position, typename next<Position>::type
    >
{ };

template <typename Sequence, typename First, typename Last>
struct dispatch<tag::default_<tag::erase>, Sequence, First, Last>
    : erase_detail::erase_impl<Sequence, First, Last>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_ERASE_HPP