/*!
 * @file
 * Defines `boost::mpl11::none_of`.
 */

#ifndef BOOST_MPL11_ALGORITHM_NONE_OF_HPP
#define BOOST_MPL11_ALGORITHM_NONE_OF_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/algorithm/none_of_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


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

#endif // !BOOST_MPL11_ALGORITHM_NONE_OF_HPP
