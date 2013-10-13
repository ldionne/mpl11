/*!
 * @file
 * Forward declares `boost::mpl11::view::indexed_by`.
 */

#ifndef BOOST_MPL11_VIEW_INDEXED_BY_FWD_HPP
#define BOOST_MPL11_VIEW_INDEXED_BY_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/functional/quote_fwd.hpp>
#include <boost/mpl11/identity_fwd.hpp>


namespace boost { namespace mpl11 { namespace view {
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
    struct indexed_by BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_INDEXED_BY_FWD_HPP
