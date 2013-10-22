/*!
 * @file
 * Forward declares `boost::mpl11::algorithm::find`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FIND_FWD_HPP
#define BOOST_MPL11_ALGORITHM_FIND_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct find; }

namespace algorithm {
    /*!
     * @ingroup algorithms
     *
     * Returns an iterator to the first occurence of a given element in a
     * sequence, or the past-the-end iterator if no such element exists.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `find_if<Sequence, equal_to<Element, _1>>`.
     */
    template <typename Sequence, typename Element>
    struct find
        : dispatch<tag::find, Sequence, Element>
    { };
} // end namespace algorithm
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_FIND_FWD_HPP
