/*!
 * @file
 * Defines `boost::mpl11::none_of`.
 */

#ifndef BOOST_MPL11_NONE_OF_HPP
#define BOOST_MPL11_NONE_OF_HPP

#include <boost/mpl11/fwd/none_of.hpp>

#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/identity.hpp> // for default Predicate
#include <boost/mpl11/quote.hpp>    //


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Predicate>
    struct none_of
        : equal<
            typename find_if<Sequence, Predicate>::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NONE_OF_HPP
