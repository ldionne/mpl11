/*!
 * @file
 * This file defines the `boost::mpl11::none_of` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_NONE_OF_HPP
#define BOOST_MPL11_ALGORITHM_NONE_OF_HPP

#include <boost/mpl11/algorithm/any_of.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    struct none_of : detail::tag_dispatched<none_of> {
        struct mpl11 {
            struct returns_integral_c;

            struct default_implementation {
                template <typename Sequence, typename Pred>
                struct apply
                    : not_<any_of<Sequence, Pred>>
                { };
            };
        };
    };
} // end namespace algorithm

template <typename Sequence, typename Pred = quote<identity>>
struct none_of
    : apply_raw<algorithm::none_of, Sequence, Pred>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_NONE_OF_HPP
