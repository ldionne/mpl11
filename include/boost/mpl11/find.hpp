/*!
 * @file
 * Defines `boost::mpl11::find`.
 */

#ifndef BOOST_MPL11_FIND_HPP
#define BOOST_MPL11_FIND_HPP

#include <boost/mpl11/fwd/find.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/lambda.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct find
        : find_if<Sequence, lambda<equal<Element, _0>>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIND_HPP
