/*!
 * @file
 * Defines `boost::mpl11::none_of`.
 */

#ifndef BOOST_MPL11_NONE_OF_HPP
#define BOOST_MPL11_NONE_OF_HPP

#include <boost/mpl11/fwd/none_of.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/find_if.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<tag::default_<tag::none_of>, Sequence>
        : none_of<Sequence, _1>
    { };

    template <typename Sequence, typename Predicate>
    struct dispatch<tag::default_<tag::none_of>, Sequence, Predicate>
        : equal_to<
            typename find_if<Sequence, Predicate>::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NONE_OF_HPP
