/*!
 * @file
 * Defines `boost::mpl11::container::vector`.
 */

#ifndef BOOST_MPL11_CONTAINER_VECTOR_HPP
#define BOOST_MPL11_CONTAINER_VECTOR_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/container/vector_fwd.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/at_fwd.hpp>
#include <boost/mpl11/intrinsic/begin_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/clear_fwd.hpp>
#include <boost/mpl11/intrinsic/deref_fwd.hpp>
#include <boost/mpl11/intrinsic/end_fwd.hpp>
#include <boost/mpl11/intrinsic/is_empty_fwd.hpp>
#include <boost/mpl11/intrinsic/next_fwd.hpp>
#include <boost/mpl11/intrinsic/prior_fwd.hpp>
#include <boost/mpl11/intrinsic/push_back_fwd.hpp>
#include <boost/mpl11/intrinsic/push_front_fwd.hpp>
#include <boost/mpl11/intrinsic/size_fwd.hpp>
#include <boost/mpl11/operator/less_fwd.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace vector_detail {
    template <unsigned long Position, typename Vector>
    struct iterator;
}

template <unsigned long Position, typename Vector>
struct dispatch<tag::next, vector_detail::iterator<Position, Vector>>
    : identity<
        vector_detail::iterator<Position + 1, Vector>
    >
{ };

template <unsigned long Position, typename Vector>
struct dispatch<tag::prior, vector_detail::iterator<Position, Vector>>
    : identity<
        iterator<Position - 1, Vector>
    >
{ };

template <unsigned long Position, typename Vector>
struct dispatch<tag::category_of, vector_detail::iterator<Position, Vector>>
    : identity<category::random_access_iterator>
{ };

template <unsigned long Position, typename Vector>
struct dispatch<tag::deref, vector_detail::iterator<Position, Vector>>
    : at_c<Vector, Position>
{ };

template <unsigned long P1, unsigned long P2, typename Vector>
struct dispatch<tag::less,
    vector_detail::iterator<P1, Vector>,
    vector_detail::iterator<P2, Vector>
>
    : identity<bool_<(P1 < P2)>>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the container
//////////////////////////////////////////////////////////////////////////////
namespace container {
    /*!
     * Metafunction returning a `vector` containing the elements
     * in the range delimited by [`First`, `Last`).
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
        vector_detail::iterator<
            0, container::vector<Elements...>
        >
    >
{ };

template <typename ...Elements>
struct dispatch<tag::end, container::vector<Elements...>>
    : identity<
        vector_detail::iterator<
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
