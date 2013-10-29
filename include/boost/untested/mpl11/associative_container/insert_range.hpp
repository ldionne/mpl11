/*!
 * @file
 * Defines `boost::mpl11::AssociativeContainer::insert_range`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_CONTAINER_INSERT_RANGE_HPP
#define BOOST_MPL11_ASSOCIATIVE_CONTAINER_INSERT_RANGE_HPP

#include <boost/mpl11/associative_container/associative_container.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    //! @todo A better implementation is not too hard to think of.
    template <typename AC, typename Iterable>
    struct AssociativeContainer::insert_range
        : foldl<
            Iterable, typename clear<AC>::type, quote<insert>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_CONTAINER_INSERT_RANGE_HPP
