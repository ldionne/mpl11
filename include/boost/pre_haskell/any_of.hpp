/*!
 * @file
 * Defines `boost::mpl11::any_of`.
 */

#ifndef BOOST_MPL11_ANY_OF_HPP
#define BOOST_MPL11_ANY_OF_HPP

#include <boost/mpl11/fwd/any_of.hpp>

#include <boost/mpl11/identity.hpp> // for default Predicate
#include <boost/mpl11/none_of.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp> // for default Predicate


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Predicate>
    struct any_of
        : not_<none_of<Sequence, Predicate>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ANY_OF_HPP
