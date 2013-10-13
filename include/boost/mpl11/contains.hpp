/*!
 * @file
 * Defines `boost::mpl11::contains`.
 */

#ifndef BOOST_MPL11_CONTAINS_HPP
#define BOOST_MPL11_CONTAINS_HPP

#include <boost/mpl11/fwd/contains.hpp>

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/find.hpp>
#include <boost/mpl11/not_equal_to.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::contains>, Sequence, Element>
        : not_equal_to<
            typename find<Sequence, Element>::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINS_HPP
