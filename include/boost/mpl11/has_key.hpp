/*!
 * @file
 * Defines `boost::mpl11::has_key`.
 */

#ifndef BOOST_MPL11_HAS_KEY_HPP
#define BOOST_MPL11_HAS_KEY_HPP

#include <boost/mpl11/fwd/has_key.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/not_equal_to.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key>
    struct dispatch<detail::default_<tag::has_key>, Sequence, Key>
        : not_equal_to<
            typename find_if<
                Sequence,
                equal_to<Key, key_of<Sequence, _1>>
            >::type,
            typename end<Sequence>::type
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HAS_KEY_HPP
