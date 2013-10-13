/*!
 * @file
 * Defines `boost::mpl11::all_of`.
 */

#ifndef BOOST_MPL11_ALL_OF_HPP
#define BOOST_MPL11_ALL_OF_HPP

#include <boost/mpl11/fwd/all_of.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/none_of.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Predicate>
    struct dispatch<tag::default_<tag::all_of>, Sequence, Predicate>
        : none_of<
            Sequence,
            not_<apply_wrap<typename lambda<Predicate>::type, _1>>
        >
    { };

    template <typename Sequence>
    struct dispatch<tag::default_<tag::all_of>, Sequence>
        : all_of<Sequence, _1>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALL_OF_HPP
