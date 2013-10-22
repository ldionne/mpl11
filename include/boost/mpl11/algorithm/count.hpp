/*!
 * @file
 * Defines `boost::mpl11::algorithm::count`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COUNT_HPP
#define BOOST_MPL11_ALGORITHM_COUNT_HPP

#include <boost/mpl11/algorithm/count_fwd.hpp>
#include <boost/mpl11/algorithm/count_if.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::count>, Sequence, Element>
        : algorithm::count_if<Sequence, equal_to<Element, _1>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_COUNT_HPP
