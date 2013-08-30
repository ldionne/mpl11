/*!
 * @file
 * Defines `boost::mpl11::copy`.
 */

#ifndef BOOST_MPL11_COPY_HPP
#define BOOST_MPL11_COPY_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/foldr.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/push_front.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename From, typename To, typename Insert = detail::optional>
struct copy;

/*!
 * Copies the content of a sequence from a sequence to another using a
 * custom operation for insertion.
 *
 * The default implementation is equivalent to
 * `foldl<From, To, lambda<Insert>::type>`.
 *
 * @warning
 * Differences from the original MPL:
 * - Inserters are not used in this version; the destination sequence and
 *   the operation are specified separately.
 */
template <typename From, typename To, typename Insert>
struct copy
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    <From, To, Insert>
#endif
    : detail::tag_dispatched<tag::copy, From, To, Insert>::template
      with_default<foldl<_2, _3, lambda<_4>>>
{ };

namespace copy_detail {
template <unsigned int N> struct priority : priority<N - 1> { };
template <> struct priority<0> { };

template <typename From, typename To>
auto copy_dispatch(category::back_extensible_sequence*, priority<3>*)
    -> foldl<From, To, push_back<_1, _2>>
;

template <typename From, typename To>
auto copy_dispatch(category::extensible_associative_sequence*, priority<2>*)
    -> foldl<From, To, insert<_1, _2>>
;

template <typename From, typename To>
auto copy_dispatch(category::front_extensible_sequence*, priority<1>*)
    -> foldr<From, To, push_front<_1, _2>>
;

template <typename From, typename To, typename ...Insert>
struct pick_best_copy
    : decltype(
        copy_dispatch<From, To>(
            (typename category_of<To>::type*)nullptr,
            (priority<4>*)nullptr
        )
    )
{ };
} // end namespace copy_detail

/*!
 * Copies the content of a sequence from a sequence to another.
 *
 * @warning
 * Differences from the original MPL:
 * - Inserters are not used in this version.
 * - It is mandatory to specify a destination sequence.
 */
template <typename From, typename To>
struct copy<From, To>
    : detail::tag_dispatched<tag::copy, From, To>::template
      with_default<copy_detail::pick_best_copy<_2, _3>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COPY_HPP
