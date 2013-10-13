/*!
 * @file
 * Defines `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/fwd/vector.hpp>

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/clear.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/prior.hpp>
#include <boost/mpl11/fwd/push_front.hpp>
#include <boost/mpl11/fwd/size.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>


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
/*!
 * Metafunction returning a `vector` containing the elements
 * in the range delimited by [`First`, `Last`).
 */
template <typename First, typename Last>
struct vector<First, Last>
    : foldl<iterator_range<First, Last>, vector<>, quote<push_back>>
{ };

template <typename ...Elements>
struct dispatch<tag::category_of, vector<Elements...>>
    : identity<
        category::random_access_sequence
    >
{ };

// BidirectionalSequence (because of the iterators)
template <typename ...Elements>
struct dispatch<tag::begin, vector<Elements...>>
    : identity<
        vector_detail::iterator<
            0, vector<Elements...>
        >
    >
{ };

template <typename ...Elements>
struct dispatch<tag::end, vector<Elements...>>
    : identity<
        vector_detail::iterator<
            sizeof...(Elements), vector<Elements...>
        >
    >
{ };

template <typename ...Elements>
struct dispatch<tag::size, vector<Elements...>>
    : identity<ulong<sizeof...(Elements)>>
{ };

template <typename ...Elements>
struct dispatch<tag::is_empty, vector<Elements...>>
    : identity<bool_<sizeof...(Elements) == 0>>
{ };

template <typename ...Elements, typename N>
struct dispatch<tag::at, vector<Elements...>, N>
    : detail::variadic_at<N, Elements...>
{ };

template <typename ...Elements>
struct dispatch<tag::clear, vector<Elements...>>
    : identity<vector<>>
{ };

template <typename ...Elements, typename T>
struct dispatch<tag::push_front, vector<Elements...>, T>
    : identity<vector<T, Elements...>>
{ };

template <typename ...Elements, typename T>
struct dispatch<tag::push_back, vector<Elements...>, T>
    : identity<vector<Elements..., T>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VECTOR_HPP
