/*!
 * @file
 * Defines `boost::mpl11::algorithm::find`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FIND_HPP
#define BOOST_MPL11_ALGORITHM_FIND_HPP

#include <boost/mpl11/algorithm/find_fwd.hpp>
#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::find>, Sequence, Element>
        : algorithm::find_if<Sequence, equal_to<Element, _1>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_FIND_HPP
