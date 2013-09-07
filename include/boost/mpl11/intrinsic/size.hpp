/*!
 * @file
 * Defines `boost::mpl11::intrinsic::size`.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the number of elements in a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `distance<begin<Sequence>::type, end<Sequence>::type>`.
     */
    template <typename Sequence>
    struct size
        : dispatch<tag::size, Sequence>
    { };
}}} // end namespace boost::mpl11::intrinsic

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/size.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_SIZE_HPP
