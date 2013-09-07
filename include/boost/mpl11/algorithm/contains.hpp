/*!
 * @file
 * Defines `boost::mpl11::algorithm::contains`.
 */

#ifndef BOOST_MPL11_ALGORITHM_CONTAINS_HPP
#define BOOST_MPL11_ALGORITHM_CONTAINS_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns whether `Sequence` contains one or more elements identical
     * to `Element`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            not_equal_to<
                find<Sequence, Element>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence, typename Element>
    struct contains
        : dispatch<tag::contains, Sequence, Element>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/contains.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_CONTAINS_HPP
