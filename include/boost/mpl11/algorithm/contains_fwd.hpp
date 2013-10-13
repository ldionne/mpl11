/*!
 * @file
 * Forward declares `boost::mpl11::contains`.
 */

#ifndef BOOST_MPL11_ALGORITHM_CONTAINS_FWD_HPP
#define BOOST_MPL11_ALGORITHM_CONTAINS_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct contains; }

    /*!
     * @ingroup algorithms
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_CONTAINS_FWD_HPP
