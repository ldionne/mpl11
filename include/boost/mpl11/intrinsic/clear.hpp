/*!
 * @file
 * Defines `boost::mpl11::clear`.
 */

#ifndef BOOST_MPL11_INTRINSIC_CLEAR_HPP
#define BOOST_MPL11_INTRINSIC_CLEAR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns an empty sequence concept-identical to `Sequence`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            erase<
                Sequence,
                begin<Sequence>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence>
    struct clear
        : dispatch<tag::clear, Sequence>
    { };
}} // end namespace boost::mpl11

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/clear.hpp>
#endif

#endif // !BOOST_MPL11_INTRINSIC_CLEAR_HPP
