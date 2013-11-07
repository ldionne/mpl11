/*!
 * @file
 * Defines `boost::mpl11::at`.
 */

#ifndef BOOST_MPL11_AT_HPP
#define BOOST_MPL11_AT_HPP

#include <boost/mpl11/fwd/at.hpp>

#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/integral_c.hpp> // for at_c


namespace boost { namespace mpl11 {
// The definitions of at below clash with the desired definition of at
// for Doxygen, because at is an overloaded name.
#ifndef BOOST_MPL11_DOXYGEN_INVOKED
    template <typename Sequence, typename Key, typename Default>
    struct at
        : class_of<Sequence>::type::template at_impl<Sequence, Key, Default>
    { };

    template <typename Sequence, typename KeyOrIndex>
    struct at<Sequence, KeyOrIndex>
        : class_of<Sequence>::type::template at_impl<Sequence, KeyOrIndex>
    { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AT_HPP
