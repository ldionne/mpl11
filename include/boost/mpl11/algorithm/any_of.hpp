/*!
 * @file
 * Defines `boost::mpl11::any_of`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ANY_OF_HPP
#define BOOST_MPL11_ALGORITHM_ANY_OF_HPP

#include <boost/mpl11/algorithm/any_of_fwd.hpp>
#include <boost/mpl11/algorithm/none_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/operator/not.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Predicate>
    struct dispatch<tag::default_<tag::any_of>, Sequence, Predicate>
        : not_<none_of<Sequence, Predicate>>
    { };

    template <typename Sequence>
    struct dispatch<tag::default_<tag::any_of>, Sequence>
        : any_of<Sequence, _1>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_ANY_OF_HPP
