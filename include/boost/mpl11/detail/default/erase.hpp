/*!
 * @file
 * Defines the default implementation of `boost::mpl11::intrinsic::erase`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_ERASE_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_ERASE_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined.hpp>


namespace boost { namespace mpl11 {
namespace erase_detail {
    template <typename Sequence, typename First, typename Last,
              bool = intrinsic::equal_to<
                Last, typename intrinsic::end<Sequence>::type
              >::type::value>
    struct erase_impl
        : algorithm::copy<
            view::bounded_by<
                typename intrinsic::begin<Sequence>::type, First
            >,
            typename intrinsic::clear<Sequence>::type
        >
    { };

    template <typename Sequence, typename First, typename Last>
    struct erase_impl<Sequence, First, Last, false>
        : algorithm::copy<
            view::joined<
                view::bounded_by<
                    typename intrinsic::begin<Sequence>::type, First
                >,
                view::bounded_by<
                    Last, typename intrinsic::end<Sequence>::type
                >
            >,
            typename intrinsic::clear<Sequence>::type
        >
    { };
} // end namespace erase_detail

template <typename Sequence, typename Position>
struct dispatch<detail::default_<tag::erase>, Sequence, Position>
    : intrinsic::erase<
        Sequence, Position, typename intrinsic::next<Position>::type
    >
{ };

template <typename Sequence, typename First, typename Last>
struct dispatch<detail::default_<tag::erase>, Sequence, First, Last>
    : erase_detail::erase_impl<Sequence, First, Last>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_ERASE_HPP
