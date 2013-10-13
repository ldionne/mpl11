/*!
 * @file
 * Forward declares `boost::mpl11::clear`.
 */

#ifndef BOOST_MPL11_FWD_CLEAR_HPP
#define BOOST_MPL11_FWD_CLEAR_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct clear; }

    /*!
     * @ingroup algorithms
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

#endif // !BOOST_MPL11_FWD_CLEAR_HPP
