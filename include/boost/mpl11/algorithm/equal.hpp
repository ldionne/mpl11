/*!
 * @file
 * Defines `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_ALGORITHM_EQUAL_HPP
#define BOOST_MPL11_ALGORITHM_EQUAL_HPP

#include <boost/mpl11/algorithm/all_of.hpp>
#include <boost/mpl11/algorithm/equal_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/functional/unpack_args.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/operator/and.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/view/zipped.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence1, typename Sequence2>
    struct dispatch<tag::default_<tag::equal>, Sequence1, Sequence2>
        : equal<Sequence1, Sequence2, quote<equal_to>>
    { };

    template <typename Sequence1, typename Sequence2, typename Predicate>
    struct dispatch<tag::default_<tag::equal>, Sequence1, Sequence2, Predicate>
        : and_<
            equal_to<
                typename size<Sequence1>::type,
                typename size<Sequence2>::type
            >,
            all_of<
                view::zipped<Sequence1, Sequence2>,
                unpack_args<Predicate>
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_EQUAL_HPP
