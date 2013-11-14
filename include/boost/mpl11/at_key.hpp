/*!
 * @file
 * Defines `boost::mpl11::at_key`.
 */

#ifndef BOOST_MPL11_AT_KEY_HPP
#define BOOST_MPL11_AT_KEY_HPP

#include <boost/mpl11/fwd/at_key.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key, typename Default>
    struct at_key
        : class_of<Sequence>::type::template
            at_key_impl<Sequence, Key, Default>
    { };

    template <typename Sequence, typename Key>
    struct at_key<Sequence, Key>
        : class_of<Sequence>::type::template at_key_impl<Sequence, Key>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AT_KEY_HPP
