/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_ALGORITHM_INSERT_HPP
#define BOOST_MPL11_ALGORITHM_INSERT_HPP

#include <boost/mpl11/algorithm/insert_fwd.hpp>
#include <boost/mpl11/algorithm/insert_range.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/view/single_element.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Position, typename Element>
    struct dispatch<tag::default_<tag::insert>, Sequence, Position, Element>
        : insert_range<
            Sequence, Position, view::single_element<Element>
        >
    { };

    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::insert>, Sequence, Element>
        : insert_range<
            Sequence, view::single_element<Element>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_INSERT_HPP
