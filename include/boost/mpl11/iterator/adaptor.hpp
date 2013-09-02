/*!
 * @file
 * Defines `boost::mpl11::iterator::adaptor`.
 */

#ifndef BOOST_MPL11_ITERATOR_ADAPTOR_HPP
#define BOOST_MPL11_ITERATOR_ADAPTOR_HPP

#include <boost/mpl11/algorithm/advance.hpp>
#include <boost/mpl11/algorithm/distance.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace iterator {
    /*!
     * @ingroup iterator
     */
    template <typename Wrap, typename Iterator>
    struct adaptor BOOST_MPL11_DOXYGEN_ONLY({ });
} // end namespace iterator

template <typename Wrap, typename Iterator>
struct dispatch<tag::next, iterator::adaptor<Wrap, Iterator>>
    : apply<Wrap, typename intrinsic::next<Iterator>::type>
{ };

template <typename Wrap, typename Iterator>
struct dispatch<tag::prior, iterator::adaptor<Wrap, Iterator>>
    : apply<Wrap, typename intrinsic::prior<Iterator>::type>
{ };

template <typename Wrap, typename Iterator>
struct dispatch<tag::deref, iterator::adaptor<Wrap, Iterator>>
    : intrinsic::deref<Iterator>
{ };

template <typename Wrap, typename Iterator>
struct dispatch<tag::category_of, iterator::adaptor<Wrap, Iterator>>
    : intrinsic::category_of<Iterator>
{ };

template <typename Wrap, typename Iterator, typename N>
struct dispatch<tag::advance, iterator::adaptor<Wrap, Iterator>, N>
    : apply<Wrap, typename algorithm::advance<Iterator, N>::type>
{ };

template <typename WrapFirst, typename First, typename WrapLast, typename Last>
struct dispatch<
    tag::distance,
    iterator::adaptor<WrapFirst, First>,
    iterator::adaptor<WrapLast, Last>
>
    : algorithm::distance<First, Last>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_ADAPTOR_HPP
