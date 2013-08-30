/*!
 * @file
 * Defines `boost::mpl11::at` and `boost::mpl::at_c`.
 */

#ifndef BOOST_MPL11_AT_HPP
#define BOOST_MPL11_AT_HPP

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Key, typename Default = detail::optional>
struct at;

namespace at_detail {
template <typename ...>
struct at_dispatched;

template <typename Sequence, typename Iterator>
struct value_deref
    : value_of<Sequence, typename deref<Iter>::type>
{ };

template <typename Sequence, typename Key, typename Default>
struct at_dispatched<category::associative_sequence, Sequence, Key, Default> {
private:
    using Iter = typename find_if<
        Sequence, is_same<key_of<Sequence, _1>, Key>
    >::type;

public:
    using type = typename if_<is_same<Iter, typename end<Sequence>::type>,
        identity<Default>,
        value_deref<Sequence, Iter>
    >::type::type;
};

struct not_found;

template <typename Sequence, typename Key>
struct at_dispatched<category::associative_sequence, Sequence, Key>
    : at<Sequence, Key, not_found>
{
    static_assert(!is_same<typename apply::type, not_found>::value,
    "Could not find the value associated to a given key in an associated "
    "sequence and no default return value was specified.");
};

template <typename Sequence, typename N>
struct at_dispatched<category::forward_sequence, Sequence, N> {
private:
    using Iter = typename advance<typename begin<Sequence>::type, N>::type;

    static_assert(N::type::value >= 0 &&
                  !is_same<Iter, typename end<Sequence>::type>::value,
    "Trying to access a sequence at an index that is out of bounds.");

public:
    using type = typename deref<Iter>::type;
};

template <typename Sequence, typename Key, typename ...Default>
auto at_dispatch(category::associative_sequence*) ->
    at_dispatched<category::associative_sequence, Sequence, Key, Default...>
;

template <typename Sequence, typename N>
auto at_dispatch(category::forward_sequence*) ->
    at_dispatched<category::forward_sequence, Sequence, N>
;

template <typename Sequence, typename Key, typename ...Default>
struct at_impl
    : decltype(
        at_dispatch<Sequence, Key, Default...>(
            (typename category_of<Sequence>::type*)nullptr
        )
    )
{ };
} // end namespace at_detail

/*!
 * Returns the element associated to a key in an associative sequence,
 * or a default value if no such element exists and a default is provided.
 *
 * The default implementation when no `Default` is provided is equivalent
 * to `at<AssociativeSequence, Key, X>`, where `X` is a type such that a
 * compile-time assertion is triggered if `X` is returned.
 *
 * Otherwise, when a `Default` is provided: Let `Iter` be the same as
   @code
        find_if<
            AssociativeSequence,
            is_same<key_of<AssociativeSequence, _1>, Key>
        >::type
   @endcode
 * Then, the default implementation when a `Default` is provided is
 * equivalent to `value_of<AssociativeSequence, deref<Iter>::type>`
 * if `is_same<Iter, end<AssociativeSequence>::type>::value` is
 * `false`, and `identity<Default>` otherwise.
 *
 * @warning
 * Differences from the original MPL:
 * - A default implementation is provided for associative sequences.
 * - A compile-time assertion is triggered when no `Default` is provided
 *   and `Key` can't be found.
 */
template <typename AssociativeSequence, typename Key, typename Default>
struct at
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    <AssociativeSequence, Key, Default>
#endif
    : detail::tag_dispatched<tag::at, AssociativeSequence, Key, Default>
      ::template with_default<at_detail::at_impl<_2, _3, _4>>
{ };

/*!
 * Returns the `N`th element of a sequence if `N` is in the bounds of the
 * sequence, and triggers a compile-time assertion otherwise.
 *
 * The default implementation is as follows:
 * Let `Iter` be the same as `advance<begin<Sequence>::type, N>::type`.
 * Then, the default implementation is equivalent to `deref<Iter>` if
 * `is_same<Iter, end<Sequence>::type>::value` and `N::type::value < 0`
 * are `false`, and a compile-time assertion is triggered otherwise.
 *
 * @warning
 * Differences from the original MPL:
 * - A compile-time assertion is triggered if `N` is out of the bounds of
 *   `Sequence`.
 */
template <typename Sequence, typename N>
struct at<Sequence, N>
    : detail::tag_dispatched<tag::at, Sequence, N>
      ::template with_default<at_detail::at_impl<_2, _3>>
{ };

//! Convenience alias to `at<Sequence, long_<N>>`.
template <typename Sequence, long N>
using at_c = at<Sequence, long_<N>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AT_HPP
