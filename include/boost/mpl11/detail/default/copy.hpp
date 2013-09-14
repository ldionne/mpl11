/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::copy`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_COPY_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_COPY_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/inserter/into.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct dispatch<detail::default_<tag::copy>, Sequence>
        : algorithm::copy<
            Sequence, inserter::into<typename clear<Sequence>::type>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_COPY_HPP
