/*!
 * @file
 * Defines `boost::mpl11::find`.
 */

#ifndef BOOST_MPL11_FIND_HPP
#define BOOST_MPL11_FIND_HPP

#include <boost/mpl11/fwd/find.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/find_if.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::find, Sequence, Element>
        : find_if<Sequence, equal_to<Element, _1>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIND_HPP
