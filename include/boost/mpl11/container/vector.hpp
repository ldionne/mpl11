/*!
 * @file
 * Defines `boost::mpl11::container::vector`.
 */

#ifndef BOOST_MPL11_CONTAINER_VECTOR_HPP
#define BOOST_MPL11_CONTAINER_VECTOR_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace container {
    /*!
     * @ingroup container
     * Contiguous sequence of types accessed by index.
     *
     * `vector` is a  `RandomAccessSequence`, `FrontExtensibleSequence` and
     * `BackExtensibleSequence`.
     */
    template <typename ...Elements>
    struct vector BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::container


#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace vector_detail {
    template <unsigned long Position, typename Vector>
    struct vector_iterator;

    template <typename OperationTag, unsigned long Position, typename Vector>
    struct dispatch;

    template <unsigned long Position, typename Vector>
    struct dispatch<tag::next, Position, Vector>
        : identity<
            vector_iterator<Position + 1, Vector>
        >
    { };

    template <unsigned long Position, typename Vector>
    struct dispatch<tag::prior, Position, Vector>
        : identity<
            vector_iterator<Position - 1, Vector>
        >
    { };

    template <unsigned long Position, typename Vector>
    struct dispatch<tag::category_of, Position, Vector>
        : identity<category::random_access_iterator>
    { };

    template <unsigned long Position, typename Vector>
    struct dispatch<tag::deref, Position, Vector>
        : intrinsic::at_c<Vector, Position>
    { };
} // end namespace vector_detail

template <typename Op, unsigned long Position, typename Vector>
struct dispatch<Op, vector_detail::vector_iterator<Position, Vector>>
    : vector_detail::dispatch<Op, Position, Vector>
{ };

namespace container {
    /*!
     * Metafunction returning a `vector` containing the elements in the range
     * delimited by [`First`, `Last`).
     */
    template <typename First, typename Last>
    struct vector<First, Last>
        : algorithm::copy<view::bounded_by<First, Last>, vector<>>
    { };
} // end namespace container

template <typename ...Elements>
struct dispatch<tag::category_of, container::vector<Elements...>>
    : inherit<
        category::random_access_sequence,
        category::front_extensible_sequence,
        category::back_extensible_sequence
    >
{ };

// BidirectionalSequence (because of the iterators)
template <typename ...Elements>
struct dispatch<tag::begin, container::vector<Elements...>>
    : identity<
        vector_detail::vector_iterator<
            0, container::vector<Elements...>
        >
    >
{ };

template <typename ...Elements>
struct dispatch<tag::end, container::vector<Elements...>>
    : identity<
        vector_detail::vector_iterator<
            sizeof...(Elements), container::vector<Elements...>
        >
    >
{ };

template <typename ...Elements>
struct dispatch<tag::size, container::vector<Elements...>>
    : identity<ulong<sizeof...(Elements)>>
{ };

template <typename ...Elements>
struct dispatch<tag::is_empty, container::vector<Elements...>>
    : identity<bool_<sizeof...(Elements) == 0>>
{ };


// RandomAccessSequence
template <typename ...Elements, typename N>
struct dispatch<tag::at, container::vector<Elements...>, N>
    : detail::variadic_at<N, Elements...>
{ };


// ExtensibleSequence
template <typename ...Elements>
struct dispatch<tag::clear, container::vector<Elements...>>
    : identity<container::vector<>>
{ };


// FrontExtensibleSequence
template <typename ...Elements, typename T>
struct dispatch<tag::push_front, container::vector<Elements...>, T>
    : identity<container::vector<T, Elements...>>
{ };


// BackExtensibleSequence
template <typename ...Elements, typename T>
struct dispatch<tag::push_back, container::vector<Elements...>, T>
    : identity<container::vector<Elements..., T>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_VECTOR_HPP
