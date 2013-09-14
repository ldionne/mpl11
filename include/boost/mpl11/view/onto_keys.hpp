/*!
 * @file
 * Defines `boost::mpl11::view::onto_keys`.
 */

#ifndef BOOST_MPL11_VIEW_ONTO_KEYS_HPP
#define BOOST_MPL11_VIEW_ONTO_KEYS_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     *
     * View onto the keys of an @ref AssociativeSequence.
     *
     * The category of `onto_keys` depends on the category of the
     * underlying `Sequence`.
     */
    template <typename Sequence>
    struct onto_keys BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view


#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/view/transformed.hpp>


namespace boost { namespace mpl11 {
template <typename OperationTag, typename Sequence, typename ...Args>
struct dispatch<OperationTag, view::onto_keys<Sequence>, Args...>
    : dispatch<
        OperationTag,
        view::transformed<Sequence, key_of<Sequence, _1>>,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_ONTO_KEYS_HPP
