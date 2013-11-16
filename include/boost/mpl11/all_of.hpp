/*!
 * @file
 * Defines `boost::mpl11::all_of`.
 */

#ifndef BOOST_MPL11_ALL_OF_HPP
#define BOOST_MPL11_ALL_OF_HPP

#include <boost/mpl11/fwd/all_of.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/identity.hpp> // for default Predicate
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/none_of.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp> // for default Predicate


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Predicate>
    struct all_of
        : none_of<Sequence, lambda<not_<apply<Predicate, _0>>>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALL_OF_HPP
