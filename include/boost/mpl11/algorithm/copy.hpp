/*!
 * @file
 * This file defines the `boost::mpl11::copy` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_COPY_HPP
#define BOOST_MPL11_ALGORITHM_COPY_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    struct copy : detail::tag_dispatched<copy> {
        struct mpl11 {
            struct default_implementation {
                template <typename Sequence, typename Inserter>
                struct apply
                    : boost::mpl11::foldl<
                        Sequence,
                        typename Inserter::state,
                        typename Inserter::operation
                    >
                { };
            };
        };
    };
} // end namespace algorithm

template <typename Sequence, typename Inserter>
struct copy
    : apply_raw<algorithm::copy, Sequence, Inserter>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_COPY_HPP
