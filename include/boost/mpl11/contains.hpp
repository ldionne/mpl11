/*!
 * @file
 * Defines `boost::mpl11::contains`.
 */

#ifndef BOOST_MPL11_CONTAINS_HPP
#define BOOST_MPL11_CONTAINS_HPP

#include <boost/mpl11/fwd/contains.hpp>

#include <boost/mpl11/any_of.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/lambda.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct contains
        : any_of<Sequence, lambda<equal<Element, _0>>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINS_HPP
