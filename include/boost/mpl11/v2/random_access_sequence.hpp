/*!
 * @file
 * Defines `boost::mpl11::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/fwd/random_access_sequence.hpp>

#include <boost/mpl11/integral_c.hpp> // required by fwd declaration
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct RandomAccessSequence { }; }

    template <typename S, typename Start, typename Stop>
    struct slice
        : RandomAccessSequence<typename tag_of<S>::type>::
            template slice_impl<S, Start, Stop>
    { };

    template <typename S, typename Index>
    struct at
        : RandomAccessSequence<typename tag_of<S>::type>::
            template at_impl<S, Index>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP
