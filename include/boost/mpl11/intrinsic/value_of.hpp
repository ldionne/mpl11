/*!
 * @file
 * Defines `boost::mpl11::intrinsic::value_of`.
 */

#ifndef BOOST_MPL11_INTRINSIC_VALUE_OF_HPP
#define BOOST_MPL11_INTRINSIC_VALUE_OF_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the value that _would_ be used for an element
     * in an `AssociativeSequence`.
     */
    template <typename Sequence, typename Element>
    struct value_of
        : detail::tag_dispatched<tag::value_of, Sequence, Element>
          ::template with_default<>
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_VALUE_OF_HPP
