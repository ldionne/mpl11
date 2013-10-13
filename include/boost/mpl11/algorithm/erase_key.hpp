/*!
 * @file
 * Defines `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ERASE_KEY_HPP
#define BOOST_MPL11_ALGORITHM_ERASE_KEY_HPP

#include <boost/mpl11/algorithm/erase_key_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/intrinsic/value_of.hpp>
#include <boost/mpl11/operator/not_equal_to.hpp>
#include <boost/mpl11/view/filtered.hpp>
#include <boost/mpl11/view/indexed_by.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key>
    struct dispatch<tag::default_<tag::erase_key>, Sequence, Key>
        : identity<
            view::indexed_by<
                view::filtered<
                    Sequence,
                    not_equal_to<Key, key_of<Sequence, _1>>
                >,
                typename lambda<key_of<Sequence, _1>>::type,
                typename lambda<value_of<Sequence, _1>>::type
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_ERASE_KEY_HPP
