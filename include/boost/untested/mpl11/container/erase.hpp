/*!
 * @file
 * Defines `boost::mpl11::Container::erase`.
 */

#ifndef BOOST_MPL11_CONTAINER_ERASE_HPP
#define BOOST_MPL11_CONTAINER_ERASE_HPP

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/container/container.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/erase.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/renew.hpp>


namespace boost { namespace mpl11 {
    template <typename C, typename Position>
    struct Container::erase<C, Position>
        : mpl11::erase<C, Position, typename next<Position>::type>
    { };

    namespace container_detail {
        template <
            typename Sequence, typename First, typename Last,
            bool = equal_to<Last, typename end<Sequence>::type>::type::value
        >
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
    } // end namespace container_detail

    template <typename C, typename First, typename Last>
    struct Container::erase
        : renew<C,
            typename container_detail::erase_impl<C, First, Last>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_ERASE_HPP
