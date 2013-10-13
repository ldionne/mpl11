/*!
 * @file
 * Forward declares `boost::mpl11::value_of`.
 */

#ifndef BOOST_MPL11_FWD_VALUE_OF_HPP
#define BOOST_MPL11_FWD_VALUE_OF_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct value_of; }

    /*!
     * @ingroup intrinsics
     *
     * Returns the value that _would_ be used for an element
     * in an @ref AssociativeSequence.
     */
    template <typename Sequence, typename Element>
    struct value_of
        : dispatch<tag::value_of, Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_VALUE_OF_HPP
