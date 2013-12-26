/*!
 * @file
 * Defines `boost::mpl11::at`.
 */

#ifndef BOOST_MPL11_AT_HPP
#define BOOST_MPL11_AT_HPP

#include <boost/mpl11/v2/fwd/at.hpp>

#include <boost/mpl11/integral_c.hpp> // required by fwd/at.hpp
#include <boost/mpl11/v2/fwd/random_access_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S, typename Index>
    struct at
        : RandomAccessSequence<typename tag_of<S>::type>::
            template at_impl<S, Index>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AT_HPP
