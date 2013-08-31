/*!
 * @file
 * Defines `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/copy.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace vector_detail {
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
        : at_c<Vector, Position>
    { };
} // end namespace vector_detail

template <typename Op, unsigned long Position, typename Vector>
struct dispatch<Op, vector_detail::vector_iterator<Position, Vector>>
    : vector_detail::dispatch<Op, Position, Vector>
{ };

/*!
 *
 */
template <typename ...Elements>
struct vector BOOST_MPL11_DOXYGEN_ONLY({ });

/*!
 * Metafunction returning a `vector` containing the elements in the range
 * delimited by [`First`, `Last`).
 */
template <typename First, typename Last>
struct vector
    : copy<view::bounded_by<First, Last>, vector<>>
{ };

template <typename ...Elements>
struct dispatch<tag::category_of, vector<Elements...>>
    : lazy_always<
        inherit<
            category::random_access_sequence,
            category::front_extensible_sequence,
            category::back_extensible_sequence
        >
    >
{ };

// BidirectionalSequence (because of the iterators)
template <typename ...Elements>
struct dispatch<tag::begin, vector<Elements...>>
    : always<
        vector_detail::vector_iterator<
            0, vector<Elements...>
        >
    >
{ };

template <typename ...Elements>
struct dispatch<tag::end, vector<Elements...>>
    : always<
        vector_detail::vector_iterator<
            sizeof...(Elements), vector<Elements...>
        >
    >
{ };

template <typename ...Elements>
struct dispatch<tag::size, vector<Elements...>>
    : always<ulong<sizeof...(Elements)>>
{ };

template <typename ...Elements>
struct dispatch<tag::is_empty, vector<Elements...>>
    : always<bool_<sizeof...(Elements) == 0>>
{ };


// RandomAccessSequence
template <typename ...Elements, typename N>
struct dispatch<tag::at, vector<Elements...>, N>
    : detail::variadic_at<N, Elements...>
{ };


// ExtensibleSequence
template <typename ...Elements>
struct dispatch<tag::clear, vector<Elements...>>
    : always<vector<>>
{ };


// FrontExtensibleSequence
template <typename ...Elements, typename T_Tag>
struct dispatch<tag::push_front, vector<Elements...>, T_Tag> {
    template <typename Self, typename T>
    struct apply
        : identity<vector<T, Elements...>>
    { };
};


// BackExtensibleSequence
template <typename ...Elements, typename T_Tag>
struct dispatch<tag::push_back, vector<Elements...>, T_Tag> {
    template <typename Self, typename T>
    struct apply
        : identity<vector<Elements..., T>>
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VECTOR_HPP
