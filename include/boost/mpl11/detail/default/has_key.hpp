/*!
 * @file
 * Defines the default implementaiton of `boost::mpl11::intrinsic::has_key`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_HAS_KEY_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_HAS_KEY_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/operator/not_equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Key>
struct dispatch<detail::default_<tag::has_key>, Sequence, Key>
    : not_equal_to<
        typename algorithm::find_if<
            Sequence,
            equal_to<Key, intrinsic::key_of<Sequence, _1>>
        >::type,
        typename intrinsic::end<Sequence>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_HAS_KEY_HPP
