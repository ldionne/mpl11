/*!
 * @file
 * Forward declares `boost::mpl11::indexed_view`.
 */

#ifndef BOOST_MPL11_FWD_INDEXED_VIEW_HPP
#define BOOST_MPL11_FWD_INDEXED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/fwd/quote.hpp>
#include <boost/mpl11/fwd/identity.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View onto the elements of a `Sequence`, indexed with a custom
     * key/value mapping.
     *
     * Regardless of the underlying `Sequence`, `indexed_by` is
     * an @ref AssociativeSequence.
     *
     *
     * @tparam Key
     *         A @ref LambdaExpression used to retrieve the key from
     *         an element of `Sequence`.
     *
     * @tparam Value
     *         A @ref LambdaExpression used to retrieve the value from
     *         an element of `Sequence`.
     */
    template <
        typename Sequence,
        typename Key = quote<identity>,
        typename Value = quote<identity>
    >
    struct indexed_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INDEXED_VIEW_HPP
