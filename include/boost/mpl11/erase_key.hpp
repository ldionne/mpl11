/*!
 * @file
 * Defines `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_ERASE_KEY_HPP
#define BOOST_MPL11_ERASE_KEY_HPP

#include <boost/mpl11/fwd/erase_key.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/filtered_view.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/indexed_view.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/not_equal_to.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key>
    struct dispatch<tag::erase_key, Sequence, Key>
        : identity<
            indexed_view<
                filtered_view<
                    Sequence,
                    not_equal_to<Key, key_of<Sequence, _1>>
                >,
                typename lambda<key_of<Sequence, _1>>::type,
                typename lambda<value_of<Sequence, _1>>::type
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_KEY_HPP
