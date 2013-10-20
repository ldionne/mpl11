/*!
 * @file
 * Defines `boost::mpl11::equal`.
 */

#ifndef BOOST_MPL11_EQUAL_HPP
#define BOOST_MPL11_EQUAL_HPP

#include <boost/mpl11/fwd/equal.hpp>

#include <boost/mpl11/all_of.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/unpack_args.hpp>
#include <boost/mpl11/zipped_view.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence1, typename Sequence2>
    struct dispatch<tag::equal, Sequence1, Sequence2>
        : equal<Sequence1, Sequence2, quote<equal_to>>
    { };

    template <typename Sequence1, typename Sequence2, typename Predicate>
    struct dispatch<tag::equal, Sequence1, Sequence2, Predicate>
        : and_<
            equal_to<
                typename size<Sequence1>::type,
                typename size<Sequence2>::type
            >,
            all_of<
                zipped_view<Sequence1, Sequence2>,
                unpack_args<Predicate>
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQUAL_HPP
