/*!
 * @file
 * Defines `boost::mpl11::algorithm::find`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FIND_HPP
#define BOOST_MPL11_ALGORITHM_FIND_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
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
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/find.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_FIND_HPP
