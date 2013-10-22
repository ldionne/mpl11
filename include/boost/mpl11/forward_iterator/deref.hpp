/*!
 * @file
 * Defines `boost::mpl11::ForwardIterator::deref`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERATOR_DEREF_HPP
#define BOOST_MPL11_FORWARD_ITERATOR_DEREF_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/forward_iterator/forward_iterator.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator>
    struct ForwardIterator::deref
        : detail::not_implemented<deref<Iterator>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERATOR_DEREF_HPP
