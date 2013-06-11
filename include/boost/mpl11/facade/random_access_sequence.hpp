/*!
 * @file
 * This file defines `boost::mpl11::random_access_sequence_facade`.
 */

#ifndef BOOST_MPL11_FACADE_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_FACADE_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/detail/at_facade.hpp>
#include <boost/mpl11/facade/bidirectional_sequence.hpp>
#include <boost/mpl11/intrinsic.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Impl>
struct random_access_sequence_facade : bidirectional_sequence_facade<Impl> {

};
}}}

#endif // !BOOST_MPL11_FACADE_RANDOM_ACCESS_SEQUENCE_HPP
