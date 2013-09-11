/*!
 * @file
 * Defines `boost::mpl11::iterator::transform`.
 */

#ifndef BOOST_MPL11_ITERATOR_TRANSFORM_HPP
#define BOOST_MPL11_ITERATOR_TRANSFORM_HPP

#include <boost/mpl11/adaptor.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace iterator {
    /*!
     * @ingroup iterator
     */
    template <typename Iterator, typename F>
    struct transform;
} // end namespace iterator

namespace transform_detail {
    template <typename F>
    struct transform_iterator_maker {
        struct type {
            template <typename Iterator>
            struct apply
                : identity<iterator::transform<Iterator, F>>
            { };
        };
    };
} // end namespace transform_detail

template <typename Op, typename Iterator, typename F, typename ...Args>
struct dispatch<Op, iterator::transform<Iterator, F>, Args...>
    : dispatch<
        Op,
        adaptor<
            // We hide `F`, which may be a `PlaceholderExpression`.
            typename transform_detail::transform_iterator_maker<F>::type,
            Iterator
        >,
        Args...
    >
{ };

template <typename Iterator, typename F>
struct dispatch<tag::deref, iterator::transform<Iterator, F>>
    : apply<F, typename deref<Iterator>::type>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_TRANSFORM_HPP
