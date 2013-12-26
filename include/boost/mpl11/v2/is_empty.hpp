/*!
 * @file
 * Defines `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_IS_EMPTY_HPP
#define BOOST_MPL11_IS_EMPTY_HPP

#include <boost/mpl11/v2/fwd/is_empty.hpp>

#include <boost/mpl11/v2/fwd/forward_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct is_empty
        : ForwardSequence<typename tag_of<S>::type>::template is_empty_impl<S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IS_EMPTY_HPP
