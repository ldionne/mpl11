/*!
 * @file
 * Defines `boost::mpl11::iterator::reverse`.
 */

#ifndef BOOST_MPL11_ITERATOR_REVERSE_HPP
#define BOOST_MPL11_ITERATOR_REVERSE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace iterator {
    /*!
     * @ingroup iterators
     */
    template <typename Iterator>
    struct reverse BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::iterator


#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/operator/less.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Iterator>
struct dispatch<tag::category_of, iterator::reverse<Iterator>>
    : category_of<Iterator>
{ };

template <typename Iterator>
struct dispatch<tag::deref, iterator::reverse<Iterator>>
    : deref<typename prior<Iterator>::type>
{ };

template <typename Iterator>
struct dispatch<tag::prior, iterator::reverse<Iterator>>
    : identity<
        iterator::reverse<typename next<Iterator>::type>
    >
{ };

template <typename Iterator>
struct dispatch<tag::next, iterator::reverse<Iterator>>
    : identity<
        iterator::reverse<typename prior<Iterator>::type>
    >
{ };

template <typename First, typename Last>
struct dispatch<
    tag::equal_to, iterator::reverse<First>, iterator::reverse<Last>
>
    : equal_to<First, Last>
{ };

template <typename First, typename Last>
struct dispatch<tag::less, iterator::reverse<Last>, iterator::reverse<First>>
    : less<First, Last>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_REVERSE_HPP
