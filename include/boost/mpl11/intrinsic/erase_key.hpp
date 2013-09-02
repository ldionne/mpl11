/*!
 * @file
 * Defines `boost::mpl11::intrinsic::erase_key`.
 */

#ifndef BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
#define BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP

#include <boost/mpl11/algorithm/copy.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/intrinsic/not_equal_to.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/filtered.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Erases elements associated with a given key in
     * an `AssociativeSequence`.
     *
     *
     * ### Semantics and default implementation
     * Equivalent to
       @code
            copy<
                filtered<
                    Sequence,
                    not_equal_to<Key, key_of<Sequence, _1>>
                >,
                clear<Sequence>::type
            >
       @endcode
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A default implementation is provided.
     */
    template <typename Sequence, typename Key>
    struct erase_key
        : detail::tag_dispatched<tag::erase_key, Sequence, Key>
    { };
} // end namespace intrinsic

template <typename Sequence, typename Key>
struct dispatch<detail::default_<tag::erase_key>, Sequence, Key>
    : algorithm::copy<
        view::filtered<
            Sequence,
            intrinsic::not_equal_to<Key, intrinsic::key_of<Sequence, _1>>
        >,
        typename intrinsic::clear<Sequence>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_ERASE_KEY_HPP
